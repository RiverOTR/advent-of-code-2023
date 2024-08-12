/* J.Med, mr.rivertimmothyotter@gmail.com */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 64
#define NUM_DIGS 9



int main() {
    int calib_sum, add, i;
    char line[LINE_LEN], *first, *tmp;
    char *digs[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    calib_sum=0;

    while (fgets(line, LINE_LEN, stdin) != NULL) {
        /* Get the first digit */
        first = strpbrk(line, "123456789");
        for (i = 0; i < NUM_DIGS; i++) {
            if (first == NULL) first = strstr(line, digs[i]);
            else if ((tmp = strstr(line, digs[i])) != NULL && tmp < first)
                first = tmp;
        }
        if (*first <= 57 && *first >= 48) add = ((int) *first - 48) * 10;
        else switch (*first) {
            case 'o':   add = 10;
                        break;
            case 't':   if (first[1] == 'w') add = 20;
                        else add = 30;
                        break;
            case 'f':   if (first[1] == 'o') add = 40;
                        else add = 50;
                        break;
            case 's':   if (first[1] == 'i') add = 60;
                        else add = 70;
                        break;
            case 'e':   add = 80;
                        break;
            case 'n':   add = 90;
                        break;
            default:    printf("Err: default switch statement finding first");
                        return 1;
        }
        calib_sum += add;
    }

    if (printf("%d\n", calib_sum) < 0) {
        printf("printf failed\n");
        return 1;
    }
    return 0;
}
