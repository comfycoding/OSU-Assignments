/**********************************************
 * Darlene Zouras
 * CS344 Winter 2017
 * Program 4
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>

/*********************************************************************************
 * error
 * borrowed from the examples. Prints the error message and exits the program.
 ********************************************************************************/
void error(const char *msg) { perror(msg); exit(1); }

// otp_dec acts as the client. It will accept input in the form:
// otp_dec cyphertext key port
// *** Quite a lot of this code has been borrowed by the client.c example code.
int main(int argc, char *argv[]) {
	int socketFD, portNumber, charsWritten, charsRead;
	struct sockaddr_in serverAddress;
	struct hostent* serverHostInfo;
	char buffer[4096];

	// check usage and args
	if (argc < 4) {
		fprintf(stderr, "USAGE: otp_dec ciphertext key port\n");
		exit(0);
	}
		// arg[1] is the ciphertext file
		// arg[2] is the keygen file
		// arg[3] is the port.

	// Set up the server address struct
	memset((char *)&serverAddress, '\0', sizeof(serverAddress));	// clear the address struct
	portNumber = atoi(argv[3]);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(portNumber);
	const char *hostName = "localhost";
	serverHostInfo = gethostbyname(hostName);
	if (serverHostInfo == NULL) { fprintf(stderr, "CLIENT: ERROR, no such host\n"); exit(1); }
	memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)serverHostInfo->h_addr, serverHostInfo->h_length);

	// set up the socket
	socketFD = socket(AF_INET, SOCK_STREAM, 0);
	if (socketFD < 0) error("CLIENT: ERROR opening socket");

	// connect to server
	if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) // connect socket to address
		error("CLIENT: ERROR connecting");

	/******************************************************
 	 * otp_dec_d expects to receive "otp_dec" as its
 	 * first argument, anything else and it will not respond
 	 * to another client.
	 * The daemon responds with stop or go signal
 	 *****************************************************/
	int otpBytesSent = send(socketFD, "otp_dec", 7, 0);
	if (otpBytesSent < 0) error("CLIENT: ERROR reading otp_dec to server");

	char goSignal[5];
	memset(goSignal, '\0', sizeof(5));
	charsRead = recv(socketFD, goSignal, sizeof(goSignal) - 1, 0);
	if (strcmp(goSignal, "GO") != 0)
		exit(1);

	/******************************************************
	 * The next block opens the key, finds the size,
	 * reads the contents into a buffer, and then
	 * sends the key to otp_dec_d.
	 *****************************************************/
	FILE *keyFile, *textFile;
	int keysize, textSize;

	// first, find the size of the file
	keyFile = fopen(argv[2], "rb");
	if (keyFile == NULL) error("CLIENT: ERROR opening key file");
	else {
		fseek(keyFile, 0, SEEK_END);
		keysize = ftell(keyFile);
		rewind(keyFile);
		// printf("Key file contains %d bytes\n", keysize);
	}

	textFile = fopen(argv[1], "rb");
	if (textFile == NULL) error("CLIENT: ERROR opening the ciphertext file");
	else {
		fseek(textFile, 0, SEEK_END);
		textSize = ftell(textFile);
		rewind(textFile);
	}

	// make sure that the sizes of these files are the same!!!!!
	if (textSize > keysize) {
	printf("Key is too small, generate a key with at least %d characters\n", textSize - 1);
		exit(1);
	}

	/*****************************************************
	 * Then read the contents into a buffer, and then
	 * send that to otp_dec_d.
	 ****************************************************/

	char textBuffer[4096];
	memset(buffer, '\0', sizeof(textBuffer));
	int textBytesRead = fread(textBuffer, sizeof(char), sizeof(textBuffer), textFile);
	if (textBytesRead < 0) error("CLIENT: ERROR reading from ciphertext file");

	// use this loop for the write,
	// all of the data may not be written in one call.
		int textBytesSent = send(socketFD, textBuffer, textBytesRead, 0);
		if (textBytesSent < 0) error("CLIENT: ERROR writing ciphertext to socket");
		textBytesRead -= textBytesSent;

	/*****************************************************
	 * Read key information from file,
	 * only send as many characters as is needed to
	 * encrypt the text file
	 ****************************************************/

	// Read data into a buffer.
	char keyBuffer[4096];
	int keyBytesRead = fread(keyBuffer, sizeof(char), sizeof(textBuffer), keyFile);
	if (keyBytesRead < 0) error("CLIENT: ERROR reading from keygen file");

	// FIXME while loop probably needed here
	int keyBytesSent = send(socketFD, keyBuffer, keyBytesRead, 0);	// write to the server
	if (keyBytesSent < 0) error("CLIENT: ERROR writing to socket");
	keyBytesRead -= keyBytesSent;

	/****************************************************
 	 * Finally, receive the encrypted text from otp_dec_d
 	 ***************************************************/
	memset(buffer, '\0', sizeof(buffer));
	charsRead = recv(socketFD, buffer, sizeof(buffer) - 1, 0);
	if (charsRead < 0) error("CLIENT: ERROR reading from socket");
	printf("%s\n", buffer);

	// and also close all files and connections
	fclose(textFile);
	fclose(keyFile);
	close(socketFD);
	return 0;
}
