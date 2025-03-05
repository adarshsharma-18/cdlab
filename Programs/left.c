#include <stdio.h>
#include <string.h>
void eliminateLeftRecursion(char *prod) {
    char nonTerminal = prod[0];
    char alpha[10], beta[10];
    int i = 3, j = 0, hasRecursion = 0;
    while (prod[i] != '\0') {
        if (prod[i] == '|') {
            alpha[j] = '\0';
            j = 0;
            i++;
        }
        if (prod[i] == nonTerminal) {
            hasRecursion = 1;
            i++;
            while (prod[i] != '|' && prod[i] != '\0') {
                alpha[j++] = prod[i++];
            }
            alpha[j] = '\0';
        } else {
            beta[j++] = prod[i++];
        }
    }
    beta[j] = '\0';
    if (hasRecursion) {
        printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
        printf("%c' -> %s%c' | ε\n", nonTerminal, alpha, nonTerminal);
    } else {
        printf("%s\n", prod);
    }
}
void leftFactoring(char *prod1, char *prod2) {
    char common[10], suffix1[10], suffix2[10];
    int i = 3, j = 0;
    while (prod1[i] == prod2[i] && prod1[i] != '\0') {
        common[j++] = prod1[i++];
    }
    common[j] = '\0';
    strcpy(suffix1, &prod1[i]);
    strcpy(suffix2, &prod2[i]);
    if (j > 0) {
        printf("%c -> %sX\n", prod1[0], common);
        printf("X -> %s | %s\n", suffix1[0] ? suffix1 : "ε", suffix2[0] ? suffix2 : "ε");
    } else {
        printf("%s\n%s\n", prod1, prod2);
    }
}
int main() {
    char prod1[30], prod2[30];
    printf("Enter production for left recursion (e.g., A->Aa|b): ");
    scanf("%s", prod1);
    eliminateLeftRecursion(prod1);
    printf("\nEnter first production for left factoring (e.g., B->ab): ");
    scanf("%s", prod1);
    printf("Enter second production for left factoring (e.g., B->ac): ");
    scanf("%s", prod2);
    leftFactoring(prod1, prod2);
    return 0;
}
