#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BROADCAST_ADDR "172.16.63.255"

int main()
{
    int server_socket;
    struct sockaddr_in server_addr, broadcast_addr;
    socklen_t broadcast_addr_len = sizeof(broadcast_addr);

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(12345);
    broadcast_addr.sin_addr.s_addr = inet_addr(BROADCAST_ADDR);

    int broadcast_val = 1;

    setsockopt(server_socket, SOL_SOCKET, SO_BROADCAST, &broadcast_val, sizeof(broadcast_val));

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char smessage[1024], rmessage[1024];

    while (1)
    {

        printf("Enter message to broadcast: ");

        fgets(smessage, sizeof(smessage), stdin);

        sendto(server_socket, smessage, sizeof(smessage), 0, (struct sockaddr *)&broadcast_addr, broadcast_addr_len);
    }

    close(server_socket);

    return 0;
}