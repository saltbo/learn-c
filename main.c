#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "time.h"
#include "string.h"
#include "net/server.h"

int main() {
    printf("Hello, World!\n");
    char s[] = "a1a2a3a4aa5a";
    printf("%s\n", s);
    printf("%lu\n", strlen(s));
    printf("%s\n", strchr(s, '5'));

    FILE *f = fopen("test.txt", "r");
    if (f == NULL) {
        printf("open file failed: %s\n", strerror(errno));
        return -1;
    }

    char buf[100];
    size_t r = fread(buf, strlen(buf), 2, f);
    printf("%ld\n", r);
    printf("%s\n", buf);

    printf("%d\n", atoi("1001"));
    char *gp = getenv("GOPATH");
    printf("%s\n", gp);


    time_t t;
    time(&t);
    printf("%ld\n", t);

    /* 初始化随机数发生器 */
    srand(t);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", rand() % 50);
    }
    return 0;
}
