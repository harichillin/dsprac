#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];

int top = -1;

void push(char c) {

    stack[++top] = c;

}

char pop() {

    if (top == -1)

      return -1;

    return stack[top--];

}

char peek() {

    if (top == -1)

      return -1;

    return stack[top];

}

int isEmpty() {

    return top == -1;

}

int precedence(char c) {

    if (c == '*' || c == '/')

      return 2;

    if (c == '+' || c == '-')

      return 1;

    return 0;

}

int isOperator(char c) {

    return (c == '+' || c == '-' || c == '*' || c == '/');

}

void infixToPostfix(char* infix, char* postfix) {

    int i = 0, j = 0;

    char ch, popped;

    while ((ch = infix[i++]) != '\0') {

      if (isalnum(ch)) {

         postfix[j++] = ch;

      } else if (ch == '(') {

         push(ch);

      } else if (ch == ')') {

         while (!isEmpty() && peek() != '(') {

             postfix[j++] = pop();

         }

         pop(); // discard '('

      } else if (isOperator(ch)) {

            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {

                postfix[j++] = pop();

            }

            push(ch);

        }

    }

    while (!isEmpty()) {

        postfix[j++] = pop();

    }

    postfix[j] = '\0';

}

int main() {

    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");

    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Infix Expression: %s\n", infix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;

}
