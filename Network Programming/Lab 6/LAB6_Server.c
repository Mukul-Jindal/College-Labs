#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BROADCAST_ADDR "172.16.95.255"
#define MAX_MESSAGE_LEN 1024
#define PORT 12345

int main()
{
    int client_socket;
    struct sockaddr_in server_addr, client_addr;

    socklen_t client_addr_len = sizeof(client_addr);

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int reuse_addr = 1;

    setsockopt(client_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr));

    bind(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char message[MAX_MESSAGE_LEN];

    while (1)
    {
        printf("Waiting for message from server\n");
        int bytes_recieved = recvfrom(client_socket, message, MAX_MESSAGE_LEN, 0, (struct sockaddr *)&client_addr, &client_addr_len);

        message[bytes_recieved] = '\0';

        printf("Message recieved: %s\n", message);
    }

    close(client_socket);

    return 0;
}