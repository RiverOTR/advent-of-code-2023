/* J.Med, mr.rivertimmothyotter@gmail.com */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define LINE_LEN 64



int main() {
    int calib_sum;
    size_t i;
    char line[64];
    calib_sum = 0;

    while (fgets(line, LINE_LEN, stdin) != NULL) {
        /* get first digit from line */
        i = 0;
        while (i < LINE_LEN && line[i] != '\n' && line[i] != '\0' &&
                (line[i] > 58 || line[i] < 47)) {
            i++; 
        }
        calib_sum = calib_sum + ((int) line[i] - 48) * 10;

        /* get last digit from line */
        i = strlen(line);
        while (i>0 && (line[i] > 58 || line[i] < 47)) {
            i--;
        }
        calib_sum = calib_sum + ((int) line[i] - 48);
    }

    if (printf("%d\n", calib_sum) < 0) {
        printf("printf failed\n");
        return 1;
    }
    return 0;
}
