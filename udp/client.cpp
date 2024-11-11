// C++ program to illustrate the client application in the
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // sending connection request
    //connect(clientSocket, (struct sockaddr*)&serverAddress,
    //        sizeof(serverAddress));

    // sending data
    const char* message = "Hello, server!";
    sendto(clientSocket, message, strlen(message), 0,(struct sockaddr*)&serverAddress,
            sizeof(serverAddress));

    // closing socket
    close(clientSocket);

    return 0;
}

