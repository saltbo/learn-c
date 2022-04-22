#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "time.h"
#include "string.h"
#include "net/server.h"

void syntax() {
    printf("Hello, World!\n");
    char s[] = "a1a2a3a4aa5a";
    printf("%s\n", s);
    printf("%lu\n", strlen(s));
    printf("%s\n", strchr(s, '5'));

    printf("%d\n", atoi("1001"));
    char *gp = getenv("GOPATH");
    printf("%s\n", gp);
}

void learn_random() {
    /* 初始化随机数发生器 */
    time_t t;
    srand(time(&t));
    printf("%ld\n", t);

    for (int i = 0; i < 5; ++i) {
        printf("%d\n", rand() % 50);
    }
}


void learn_enum() {
    enum AAA {
        A, B, C // 0, 1, 2
    };
    enum AAA a = B; // 正确语法
    enum AAA b = 1; // 这个允许赋值我就忍了，毕竟都是整型
    enum AAA b1 = 10; // 这也能赋值，感觉枚举了个寂寞
    enum AAA c = "a"; // 这个明显数据类型不对，居然能编译
    printf("enum: %d, %d, %d, %d, %d, %d, %d\n", A, B, C, a, b, b1, c);
}

void learn_file_op() {
    FILE *f = fopen("test.txt", "r");
    if (f == NULL) {
        printf("open file failed: %s\n", strerror(errno));
        return;
    }

    char buf[100];
    size_t r = fread(buf, strlen(buf), 2, f);
    printf("%ld\n", r);
    printf("%s\n", buf);
}

int main() {
    syntax();
    learn_enum();
    learn_random();
    learn_file_op();
    return 0;
}
