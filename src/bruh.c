#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int main() {
    char bruh[5] = "bruh\n";
    char *buf = malloc(16384);
    int bufused = 0;
    while (bufused < 16384) {
        memcpy(buf+bufused, bruh, 5);
        bufused += 5;
    }
    while (write(1, buf, 16384));
    return 1;
}
