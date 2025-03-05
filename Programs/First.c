#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PROD 10   
#define BUF_SIZE 100  
char prod[MAX_PROD][BUF_SIZE];
int n;
void addCharUnique(char *set, char c) {
    if (!strchr(set, c)) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}
void first(char c, char *firstSet) {
    if (!isupper(c)) {        
        addCharUnique(firstSet, c);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (prod[i][0] == c) {
            first(prod[i][2], firstSet);
        }
    }
}
void follow(char c, char *followSet) {
    if (prod[0][0] == c)
        addCharUnique(followSet, '$');
    for (int i = 0; i < n; i++) {
        for (int j = 2; prod[i][j] != '\0'; j++) {
            if (prod[i][j] == c) {
                if (prod[i][j + 1] != '\0')
                    first(prod[i][j + 1], followSet);
                else if (c != prod[i][0])
                    follow(prod[i][0], followSet);
            }
        }
    }
}

int main() {
    char firstSet[BUF_SIZE], followSet[BUF_SIZE];
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (e.g., A=aB):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);
    for (int i = 0; i < n; i++) {
        memset(firstSet, 0, BUF_SIZE);
        first(prod[i][2], firstSet);
        memset(followSet, 0, BUF_SIZE);
        follow(prod[i][0], followSet);
        printf("%c -> %s | FIRST: %s | FOLLOW: %s\n",
               prod[i][0], &prod[i][2], firstSet, followSet);
    }
    return 0;
}
