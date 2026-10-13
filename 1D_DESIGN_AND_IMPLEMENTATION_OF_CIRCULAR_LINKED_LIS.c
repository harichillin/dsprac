#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int val) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = val;
   newNode->next = NULL;
   return newNode;
}

void insertFront(int val) {
  struct Node* newNode = createNode(val);
  if (head == NULL) {
     newNode->next = newNode;
     head = newNode;
     return;
  }

    struct Node* temp = head;
    while (temp->next != head)
       temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertEnd(int val) {
  struct Node* newNode = createNode(val);
  if (head == NULL) {
     newNode->next = newNode;
     head = newNode;
     return;
  }
  struct Node* temp = head;
  while (temp->next != head)
     temp = temp->next;
  temp->next = newNode;
  newNode->next = head;
}

void deleteNode(int val) {
  if (head == NULL) {
     printf("List is empty!\n");
     return;
  }
  struct Node* curr = head;
  struct Node* prev = NULL;
  do {
     if (curr->data == val) {
        if (prev == NULL) {
           struct Node* last = head;
           while (last->next != head)
              last = last->next;
           if (head == head->next) {
              free(head);
              head = NULL;
           } else {
              last->next = head->next;
              head = head->next;
              free(curr);
           }
        } else {
           prev->next = curr->next;
           free(curr);
        }
        printf("Node deleted.\n");

        return;
       }
       prev = curr;
       curr = curr->next;
    } while (curr != head);
    printf("Element not found!\n");
}

void display() {
  if (head == NULL) {
     printf("List is empty!\n");
     return;
  }
  struct Node* temp = head;
  printf("Circular List: ");
  do {
     printf("%d ", temp->data);
     temp = temp->next;
  } while (temp != head);
  printf("-> (back to head: %d)\n", head->data);
}

int main() {
  insertEnd(10);
  insertEnd(20);
  insertEnd(30);
  insertFront(5);
  display();
  deleteNode(20);
  display();
  return 0;
}
