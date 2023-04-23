#include <stdio.h>

/**
 * main - prints all possible different combinations of three digits
 * Return: Always 0 (Success)
 */

int main(void) {
    int i, j, k;
    for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            for (k = j + 1; k < 9; k++) {
                putchar(i%3 + '0');
                putchar(j%3 + '0');
                putchar(k%3 + '0');
                if (i != 6 || j != 7 || k != 8) {
                    putchar(',');
                    putchar(' ');
                }
            }
        }
    }
    return 0;
}
