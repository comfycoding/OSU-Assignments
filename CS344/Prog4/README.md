These C programs are examples of client-server communication through packets.
keygen.c creates a key of a specified length, used to encrypt string data.
The files otp-enc-d and otp-dec-d are daemons that wait for communication from otp-enc and otp-dec. Text from a file is sent from the client to the server, encrypted one way and decrypted the other.
