#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
   int coeff;
   int exp;
   struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** head, int coeff, int exp) {
  struct Node* newNode = createNode(coeff, exp);
  if (*head == NULL) {
     *head = newNode;
     return;
  }
  struct Node* temp = *head;
  while (temp->next != NULL)
     temp = temp->next;
  temp->next = newNode;
}

void display(struct Node* head) {
  if (head == NULL) {
     printf("Empty Polynomial\n");
     return;
  }
  struct Node* temp = head;
  while (temp != NULL) {
     if (temp->exp == 0)
        printf("%d", temp->coeff);
     else if (temp->exp == 1)
        printf("%dx", temp->coeff);
     else
        printf("%dx^%d", temp->coeff, temp->exp);
     if (temp->next != NULL)
        printf(" + ");
     temp = temp->next;
  }
  printf("\n");
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
   struct Node* result = NULL;
   while (p1 != NULL && p2 != NULL) {
      if (p1->exp == p2->exp) {
         insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
         p1 = p1->next;
         p2 = p2->next;
      } else if (p1->exp > p2->exp) {
         insertTerm(&result, p1->coeff, p1->exp);
         p1 = p1->next;

      } else {
         insertTerm(&result, p2->coeff, p2->exp);
         p2 = p2->next;
      }
    }
    while (p1 != NULL) {
      insertTerm(&result, p1->coeff, p1->exp);
      p1 = p1->next;
    }
    while (p2 != NULL) {
      insertTerm(&result, p2->coeff, p2->exp);
      p2 = p2->next;
    }
    return result;
}

float evaluate(struct Node* head, float x) {
   float result = 0;
   struct Node* temp = head;
   while (temp != NULL) {
      result += temp->coeff * pow(x, temp->exp);
      temp = temp->next;
   }
   return result;
}

int main() {
  struct Node* poly1 = NULL;
  struct Node* poly2 = NULL;
  struct Node* sum = NULL;

    // Polynomial 1: 3x^3 + 5x^2 + 2
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 2, 0);

    // Polynomial 2: 4x^3 + 2x^2 + 6x + 1
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 6, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    sum = addPolynomials(poly1, poly2);
    printf("Sum:   ");
    display(sum);

    printf("Evaluation of Polynomial 1 at x=2: %.2f\n", evaluate(poly1, 2));
    printf("Evaluation of Sum at x=2:      %.2f\n", evaluate(sum, 2));

    return 0;
}
