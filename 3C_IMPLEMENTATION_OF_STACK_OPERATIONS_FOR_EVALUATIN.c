#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];

int top = -1;

void push(int val) {

    stack[++top] = val;

}

int pop() {

    if (top == -1) {

     printf("Stack Underflow!\n");

     exit(1);
  }
  return stack[top--];
}
int isEmpty() {
   return top == -1;
}

int evaluatePostfix(char* expr) {

  int i = 0;

  char ch;

  while ((ch = expr[i++]) != '\0') {

     if (isdigit(ch)) {

       push(ch - '0');

     } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

       int right = pop();

       int left = pop();

       int result;

       switch (ch) {

          case '+': result = left + right; break;

          case '-': result = left - right; break;

          case '*': result = left * right; break;

          case '/':

                if (right == 0) {

                    printf("Error: Division by zero!\n");

                    exit(1);

                }

                 result = left / right;

                 break;

            }

            push(result);

        }

    }

    return pop();

}

int main() {

    char expr[MAX];

    printf("Enter Postfix Expression: ");

    scanf("%s", expr);

    int result = evaluatePostfix(expr);

    printf("Postfix Expression: %s\n", expr);

    printf("Evaluated Result: %d\n", result);

    return 0;

}
