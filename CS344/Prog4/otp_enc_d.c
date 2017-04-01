/**********************************************
 * Darlene Zouras
 * CS344 Winter 2017
 * Prog 4
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*****************************************************************************
 * error
 * borrowed from the class examples, prints error message
 ****************************************************************************/
void error(const char *msg) { perror(msg); exit(1); }

// otp_enc_d is a faux daemon that works as a server that encodes text passed from a client
// It is called in this format:
// otp_enc_d port (&)
// A lot of this code is borrowed from the class example server.c
int main(int argc, char *argv[]) {
	int listenSocketFD, establishedConnectionFD, portNumber, charsRead;
	socklen_t sizeOfClientInfo;
	char buffer[4096];
	struct sockaddr_in serverAddress, clientAddress;

	// check usage and args
	if (argc < 2) {
		fprintf(stderr, "USAGE: otp_enc_d port (&)\n");
		exit(1);
	}

	// set up the address struct for this process
	memset((char *)&serverAddress, '\0', sizeof(serverAddress));	// clear the address struct
	portNumber = atoi(argv[1]);		// get the port number and convert from string
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(portNumber);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	// set up the socket
	listenSocketFD = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocketFD < 0) error("ERROR opening socket");

	// Enable the socket to being listening, connect socket to port
	if (bind(listenSocketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
		error("ERROR on binding");
	listen(listenSocketFD, 5);		// flip the socket on, it can receive up to 5 connections

	while(1) {
		pid_t childPid = -5;
		// accept a connection in, block if one is not available until one connects
		sizeOfClientInfo = sizeof(clientAddress);	// get the size of the address for the client

		establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo);
		if (establishedConnectionFD < 0) error("ERROR on accept");

		// fork a child on accept
		childPid = fork();
		if (childPid == -1) error ("SERVER: ERROR forking child on accept");
		if (childPid == 0) {
			/*****************************************
			 * In order to confirm that we are receiving
			 * from otp_enc, this program expects that
			 * the first arg sent is "otp_enc".
			 ****************************************/
			char otpBuffer[256];
			memset(otpBuffer, '\0', sizeof(otpBuffer));
			charsRead = recv(establishedConnectionFD, otpBuffer, sizeof(otpBuffer)-1, 0);
			// printf("Communicating with %s\n", otpBuffer);
			if (strcmp(otpBuffer, "otp_enc") != 0) {
				send(establishedConnectionFD, "STOP", 4, 0);
				error("SERVER: Please connect to otp_enc_d only with otp_enc!");
			}
			else
				send(establishedConnectionFD, "GO", 2, 0);

			/*****************************************
			 * Receive the text file from the client
			 * the plaintext will be held in textBuffer
			 ****************************************/
			char textBuffer[4096];
			memset(textBuffer, '\0', sizeof(textBuffer));
			charsRead = recv(establishedConnectionFD, textBuffer, sizeof(textBuffer)-1, 0);
			if (charsRead < 0) error("ERROR reading plaintext from socket");

			textBuffer[strlen(textBuffer) - 1] = '\0';
			// printf("SERVER: I received this plaintext: %s\n", textBuffer);

			/*****************************************
 			 * Receive the key from the client
 			 * The key will be held in keyBuffer
 			 ****************************************/
			char keyBuffer[4096];
			memset(keyBuffer, '\0', sizeof(4096));
			charsRead = recv(establishedConnectionFD, keyBuffer, sizeof(keyBuffer)-1, 0);
			if (charsRead < 0) error("ERROR reading key from socket");

			keyBuffer[strlen(keyBuffer) - 1] = '\0';
			// printf("SERVER: I received this key: %s\n", keyBuffer);

			/*************************************************
 			 * Encrypt the files by adding the the ASCII integer
 			 * of the plaintext file and the key file, then subtract 65
 			 * so that it will still be a letter A-Z.
 			 * If the character is a space, it will remain a space.
 			 ************************************************/
			int i, num;
			char encryptBuffer[4096];
			memset(encryptBuffer, '\0', sizeof(encryptBuffer));
			// printf("SERVER: encrypting now...\n");
			for (i = 0; i < strlen(textBuffer); i++) {
				if (textBuffer[i] == ' ') {
					encryptBuffer[i] = ' ';
				}
				else {
					// working with the mod26 here!
					num = (textBuffer[i]-65) + (keyBuffer[i]-65);
					if (num >= 26)
						num = num - 26;
					encryptBuffer[i] = num + 65;
				}
			}

			// finally, return the encrypted text!
			charsRead = send(establishedConnectionFD, encryptBuffer, strlen(encryptBuffer), 0);
			if (charsRead < 0) error("ERROR writing to socket");

			close(establishedConnectionFD);
			exit(0);
			}

		// don't forget to clean up children
		waitpid(childPid, 0, 0);
	}

	close(listenSocketFD);
	return 0;
}
