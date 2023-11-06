#include <stdio.h>
#include <string.h>

char *search(char *s, char *t);

int main() {
    char s[30];
    char t[30];
    scanf("%s", s);
    scanf("%s", t);
    char *result = search(s, t);
    if (result != NULL) {
        printf("%ld", result - s);
    } else {
        printf("NULL");
    }
    return 0;
}

char *search(char *s, char *t) {
    return strstr(s, t);
}
