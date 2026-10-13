#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* prev;
   struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int val) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = val;
   newNode->prev = NULL;
   newNode->next = NULL;
   return newNode;
}

void insertFront(int val) {
  struct Node* newNode = createNode(val);

    if (head == NULL) {
       head = newNode;
       return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertEnd(int val) {
  struct Node* newNode = createNode(val);
  if (head == NULL) {
     head = newNode;
     return;
  }
  struct Node* temp = head;
  while (temp->next != NULL)
     temp = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
}

void deleteNode(int val) {
  struct Node* temp = head;
  while (temp != NULL && temp->data != val)
     temp = temp->next;
  if (temp == NULL) {
     printf("Element not found!\n");
     return;
  }
  if (temp->prev != NULL)
     temp->prev->next = temp->next;
  else
     head = temp->next;
  if (temp->next != NULL)
     temp->next->prev = temp->prev;
  free(temp);
  printf("Node deleted.\n");
}

void displayForward() {

    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
       printf("%d ", temp->data);
       temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
  struct Node* temp = head;
  while (temp->next != NULL)
     temp = temp->next;
  printf("Backward: ");
  while (temp != NULL) {
     printf("%d ", temp->data);
     temp = temp->prev;
  }
  printf("\n");
}

int main() {
  insertEnd(10);
  insertEnd(20);
  insertEnd(30);
  insertFront(5);
  displayForward();
  displayBackward();
  deleteNode(20);
  displayForward();
  return 0;
}
