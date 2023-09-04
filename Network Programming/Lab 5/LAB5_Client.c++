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
    int udpSocket,n;
    char sendMessage[100];
    char receiveMessage[100];
    struct sockaddr_in serverAddress;
    udpSocket = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&serverAddress,sizeof(serverAddress));

    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_family = AF_INET;

    socklen_t length;

    while (true)
    {
        cout<<"Enter the Message: "<<endl;
        fgets(sendMessage,100,stdin);
        sendto(udpSocket,sendMessage,100,MSG_CONFIRM,(const struct sockaddr * )&serverAddress,sizeof(serverAddress));
        if (strcmp(sendMessage,"exit\n")==0)
        {
            cout<<"Exiting ........."<<endl;
            close(udpSocket);
            break;
        }
        
        n = recvfrom(udpSocket,receiveMessage,100,MSG_WAITALL,(struct sockaddr *)&serverAddress,&length);

        receiveMessage[n]='\0';
        cout<<"Received Message: "<<receiveMessage<<endl;
    }
    
    return 0;
}