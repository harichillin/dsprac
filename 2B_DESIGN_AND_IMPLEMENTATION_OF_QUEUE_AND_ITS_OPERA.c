#include <stdio.h>

#include <stdlib.h>

struct Node {

     int data;

     struct Node* next;

};

struct Node* front = NULL;

struct Node* rear = NULL;

struct Node* createNode(int val) {

     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

     newNode->data = val;

     newNode->next = NULL;

     return newNode;

}

void enqueue(int val) {

  struct Node* newNode = createNode(val);

  if (rear == NULL) {

      front = rear = newNode;

      printf("Enqueued: %d\n", val);

      return;

  }

  rear->next = newNode;
  rear = newNode;
  printf("Enqueued: %d\n", val);
}
void dequeue() {
  if (front == NULL) {
     printf("Queue Underflow! Queue is empty.\n");
     return;
  }
  struct Node* temp = front;
  printf("Dequeued: %d\n", front->data);
  front = front->next;
  if (front == NULL)
     rear = NULL;
  free(temp);
}

void peek() {

  if (front == NULL) {

      printf("Queue is Empty.\n");

      return;

  }

  printf("Front element: %d\n", front->data);
}
void display() {
  if (front == NULL) {
     printf("Queue is Empty.\n");

    return;
  }
  struct Node* temp = front;
  printf("Queue (Front -> Rear): ");
  while (temp != NULL) {
     printf("%d ", temp->data);
     temp = temp->next;
  }
  printf("\n");

}
int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  display();
  peek();
  dequeue();
  dequeue();
  display();
  peek();
  return 0;
}
