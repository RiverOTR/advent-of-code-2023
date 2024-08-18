/* mr.rivertimmothyotter@gmail.com */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LEN 192
#define MAX_R 12
#define MAX_G 13
#define MAX_B 14

int main() {
    int sum, id, pull;
    char flag, line[LINE_LEN], *part;

    while (fgets(line, LINE_LEN, stdin) != NULL) {
        flag = 1;
        part = line+5;
        id = atoi(part);
        while (*part != '\n' && *part != '\0' && part < line+LINE_LEN) {
            part = strpbrk(part+1, "123456789\n\0");
            if (! *part || *part == '\n') break;
            pull = atoi(part);
            switch (*(strpbrk(part, "rgb"))) {
                case ('r'): if (pull > MAX_R) flag = 0; break;
                case ('g'): if (pull > MAX_G) flag = 0; break;
                case ('b'): if (pull > MAX_B) flag = 0; break;
                default: return 1; break;
            }
        }
        if (flag) sum += id;
    }
    if (!printf("%d\n", sum)) {
        printf("err: failed print\n");
        return 2;
    }
    return 0;
}
