#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

int main()
{
    int udpSocket, n;
    const char *sendline = "Hello this is client side message";
    char receiveLine[100];
    struct sockaddr_in serverAddress;
    if ((udpSocket = socket(AF_INET,SOCK_DGRAM,0))<0)
    {
        perror("Socket connection failed");
        exit(EXIT_FAILURE);
    }
    memset(&serverAddress,0,sizeof(serverAddress));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr=INADDR_ANY;

    socklen_t length;
    // cout<<"Enter the message to send:\n";
    // cin>>*(sendline);
    sendto(udpSocket,sendline,strlen(sendline),MSG_CONFIRM,(const struct sockaddr * ) &serverAddress,sizeof(serverAddress));

    n = recvfrom(udpSocket, receiveLine,100,MSG_WAITALL,(struct sockaddr *)&serverAddress, &length);
    receiveLine[n]='\0';
    cout<<"Server :"<<receiveLine<<endl;
    close(udpSocket);

    return 0;
}