#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX];
int n = 0; // current size

// Insert element at given position (1-based)
void insert(int pos, int element) {
  if (n == MAX) {
     printf("List Overflow! Cannot insert.\n");
     return;
  }
  if (pos < 1 || pos > n + 1) {
     printf("Invalid Position!\n");
     return;
  }
  // Shift elements to the right
  for (int i = n; i >= pos; i--) {
     arr[i] = arr[i - 1];
  }
  arr[pos - 1] = element;
  n++;
  printf("Element %d inserted at position %d.\n", element, pos);
}

// Delete element at given position (1-based)
void delete(int pos) {
  if (n == 0) {
     printf("List Underflow! List is empty.\n");
     return;
  }
  if (pos < 1 || pos > n) {
     printf("Invalid Position!\n");
     return;
  }
  int deleted = arr[pos - 1];
  // Shift elements to the left
  for (int i = pos - 1; i < n - 1; i++) {
     arr[i] = arr[i + 1];
  }
  n--;
  printf("Element %d deleted from position %d.\n", deleted, pos);
}

// Search for an element
void search(int element) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == element) {
        printf("Element %d found at position %d.\n", element, i + 1);
        return;
    }
  }
  printf("Element %d not found in the list.\n", element);
}

// Display all elements
void display() {
  if (n == 0) {
     printf("List is empty.\n");
     return;
  }
  printf("List elements: ");
  for (int i = 0; i < n; i++) {
     printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int choice, pos, element;

  while (1) {
   printf("\n===== ARRAY IMPLEMENTATION OF LIST ADT =====\n");
   printf("1. Insert\n");
   printf("2. Delete\n");
   printf("3. Search\n");
   printf("4. Display\n");
   printf("5. Exit\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter position and element: ");
        scanf("%d %d", &pos, &element);
        insert(pos, element);
        break;
      case 2:
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        delete(pos);
        break;

        case 3:
          printf("Enter element to search: ");
          scanf("%d", &element);
          search(element);
          break;
        case 4:
          display();
          break;
        case 5:
          printf("Exiting...\n");
          exit(0);
        default:
          printf("Invalid choice! Try again.\n");
      }
    }
    return 0;
}
