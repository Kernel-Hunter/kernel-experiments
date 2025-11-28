/* Test program to read /proc/hello_kmod */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("/proc/hello_kmod", "r");
    if (!f) {
        perror("fopen");
        return 1;
    }
    char buf[256];
    if (fgets(buf, sizeof(buf), f)) {
        printf("proc: %s", buf);
    } else {
        printf("no data\n");
    }
    fclose(f);
    return 0;
}
