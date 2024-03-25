#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, addrlen, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);
    addrlen = sizeof(client_addr);
    
    n = recvfrom(server_fd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&client_addr, &addrlen);
    buffer[n] = '\0';
    printf("Received from client: %s\n", buffer);
    
    sendto(server_fd, "Hello from server", strlen("Hello from server"), MSG_CONFIRM, (const struct sockaddr *)&client_addr, addrlen);
    printf("Hello message sent.\n");

    return 0;
}
