//
// Created by saltbo on 2021/10/22.
//

#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <printf.h>
#include <netinet/in.h>

int server() {
    int lsocket = socket(PF_INET,SOCK_STREAM, 0);
    if (lsocket == -1) {
        printf("socket failed: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    listen(lsocket, 0);
}