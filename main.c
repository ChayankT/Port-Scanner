#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    char ip[100];
    int start_port, end_port;

    printf("Enter target IP: ");
    scanf("%s", ip);

    printf("Enter start port: ");
    scanf("%d", &start_port);

    printf("Enter end port: ");
    scanf("%d", &end_port);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    printf("\nScanning %s from port %d to %d...\n\n", ip, start_port, end_port);

    int open_count = 0;

    for (int port = start_port; port <= end_port; port++) {

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Socket creation failed.\n");
            return 1;
        }

        struct sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(ip);

        int result = connect(sock, (struct sockaddr*)&target, sizeof(target));

        if (result == 0) {
            printf("Port %d OPEN\n", port);
            open_count++;
        }

        close(sock);
    }

    printf("\nScan complete.\n");
    printf("Total open ports: %d\n", open_count);

    return 0;
}
