/* J.Med, mr.rivertimmothyotter@gmail.com */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 64
#define NUM_DIGS 9



int main() {
    int calib_sum, add, i;
    char c, line[LINE_LEN], *first, *tmp;
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
        add = 0;

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
        
        /* Find last digit in line */
        add = 0;
        i = ((int) strlen(line)) - 1;
        while (i >= 0) {
            if ((c = line[i]) <= 57 && c >= 48) {
                add = ((int) c - 48);
                break;
            } else switch (c) {
                case 'o': if (!strncmp(line+i, "one", 3)) {
                              add = 1;
                              i = -1;
                          }
                          break;
                case 't': if (!strncmp(line+i, "two", 3)) {
                              add = 2;
                              i = -1;
                          } else if (!strncmp(line+i, "three", 5)) {
                              add = 3;
                              i = -1;
                          }
                          break;
                case 'f': if (!strncmp(line+i, "four", 4)) {
                              add = 4;
                              i = -1;
                          } else if (!strncmp(line+i, "five", 4)) {
                              add = 5;
                              i = -1;
                          }
                          break;
                case 's': if (!strncmp(line+i, "six", 3)) {
                              add = 6;
                              i = -1;
                          } else if (!strncmp(line+i, "seven", 5)) {
                              add = 7;
                              i=-1;
                          }
                          break;
                case 'e': if (!strncmp(line+i, "eight", 5)) {
                              add = 8;
                              i=-1;
                          }
                          break;
                case 'n': if (!strncmp(line+i, "nine", 4)) {
                              add = 9;
                              i=-1;
                          }
                          break;
            }
            i--;
        }
        calib_sum += add;
    }

    if (printf("%d\n", calib_sum) < 0) {
        printf("printf failed\n");
        return 1;
    }
    return 0;
}
