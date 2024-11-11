#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>

using namespace std;

int main ()
{
  int ServerSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    	char message[2000] = {0};
    	int bytes;
    	sockaddr_in clientAdress;
    	socklen_t lenclient = sizeof(clientAdress);
    	
    bind(ServerSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
    	
    //ifstream infile("temp.txt" ios::binary);
    ofstream outfile("receved.mp3", std::ios::binary);
    while((bytes = recvfrom(ServerSocket,message,sizeof(message),0,(struct sockaddr*)&clientAdress , &lenclient)) > 0)
    {
      outfile.write(message,bytes);
    }
    
    
    //sendto(clientSocket, message, strlen(message), 0,(struct sockaddr*)&serverAddress,
          //  sizeof(serverAddress));

    // sending data
    //const char* message = "Hello, server!";
    //sendto(clientSocket, message, strlen(message), 0,(struct sockaddr*)&serverAddress,
      //      sizeof(serverAddress));
      close(ServerSocket);
      return 0;
}
