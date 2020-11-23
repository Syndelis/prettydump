#include <stdio.h>
#include <string.h>

#define ESC "\033["
#define M "m"

#define CLEAN ESC M
#define LINE ESC "2;33" M
#define NONZERO ESC "4;94" M
#define ZERO ESC "96" M
#define ASTERISK ESC "34" M

#define Print(mode, x) printf(mode "%s" CLEAN " ", x)

int main() {

    char str[256], *s, *c;
    int not_zero, count;

    while (fgets(str, 256, stdin)) {

        count = 0;
        s = strtok(str, " ");
        do {

            if (!count) {
                if (*s == '*') printf(ASTERISK "*\n");
                else Print(LINE, s);
            }
            else {

                if (*s == '|') printf(CLEAN "%s", s);
                else if (*s == ' ') continue;

                else {
                    for (
                        not_zero = 1, c = s;
                        (*c) && not_zero;
                        c++, not_zero = (*c != '0')
                    );
                    if (not_zero) Print(NONZERO, s);
                    else Print(ZERO, s);
                }

            }
            count++;

        } while ((s = strtok(NULL, " ")));

    }

    printf("\n");
    return 0;

}