#include <stdio.h>
#include <string.h>

int is_palindrome(char *s)
{
    int len = strlen(s);

    if (len <= 1) {
        return 1;
    } else if (s[0] != s[len - 1]) {
        return 0; 
    } else {
        s[len - 1] = '\0';
        return is_palindrome(s + 1);  
    }
}

int main(void)
{
    int r;

    r = is_palindrome("level");
    printf("%d\n", r);
    r = is_palindrome("redder");
    printf("%d\n", r);
    r = is_palindrome("test");
    printf("%d\n", r);
    r = is_palindrome("step on no pets");
    printf("%d\n", r);
    return 0;
}

