#include <stdio.h>
#include <ctype.h>
#include <string.h>

int calculate(char *s) {
    
    int stack[1000];
    int top = -1;

    int num = 0;
    char op = '+';

    for(int i = 0; i <= strlen(s); i++) {

        if(isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if(op == '+') {
                stack[++top] = num;
            }
            else if(op == '-') {
                stack[++top] = -num;
            }
            else if(op == '*') {
                stack[top] = stack[top] * num;
            }
            else if(op == '/') {
                stack[top] = stack[top] / num;
            }

            op = s[i];
            num = 0;
        }
    }

    int result = 0;
    for(int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}

int main() {

    char s[] = "3+2*2";

    int ans = calculate(s);

    printf("Result = %d\n", ans);

    return 0;
}