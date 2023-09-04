#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <argp.h>
#include <sys/errno.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int udpSocket;
    char receiveMessage[100];
    char sendMessage[100];
    struct sockaddr_in serverAddress, clientAddress;
    // listen_fd = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&serverAddress, sizeof(serverAddress));
    bzero(&clientAddress, sizeof(clientAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    bind(udpSocket, (const struct sockaddr *)&serverAddress, sizeof(serverAddress));

    socklen_t length;
    int n;
    length = sizeof(clientAddress);

    while (true)
    {
        recvfrom(udpSocket,receiveMessage,100,0,(struct sockaddr *)&clientAddress,&length);
        // receiveMessage[n]='\0';
        cout<<"Received Message: "<<receiveMessage;
        if(strcmp(receiveMessage,"exit\n")==0)
        {
            cout<<"Exiting............\n";
            break;
        }
        cout<<"Enter Message: ";
        fgets(sendMessage,100,stdin);
        sendto(udpSocket,sendMessage,100,MSG_CONFIRM,(const struct sockaddr *)&clientAddress,sizeof(clientAddress));
    }
    return 0;
}