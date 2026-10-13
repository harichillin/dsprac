#include <stdio.h>

#include <stdlib.h>

#define MAX 100

// MAX HEAP

int maxHeap[MAX];

int maxSize = 0;

void swapMax(int* a, int* b) {

    int temp = *a;

    *a = *b;

    *b = temp;

}

void heapifyUpMax(int index) {

    int parent = (index - 1) / 2;

    while (index > 0 && maxHeap[index] > maxHeap[parent]) {

        swapMax(&maxHeap[index], &maxHeap[parent]);

        index = parent;

        parent = (index - 1) / 2;

    }

}

void heapifyDownMax(int index) {

    int largest = index;

    int left = 2 * index + 1;

    int right = 2 * index + 2;

    if (left < maxSize && maxHeap[left] > maxHeap[largest])

        largest = left;

    if (right < maxSize && maxHeap[right] > maxHeap[largest])

        largest = right;

    if (largest != index) {

        swapMax(&maxHeap[index], &maxHeap[largest]);

        heapifyDownMax(largest);

    }

}

void insertMax(int val) {

    if (maxSize >= MAX) {

        printf("Max Heap is Full!\n");

        return;

    }

    maxHeap[maxSize] = val;

    maxSize++;

    heapifyUpMax(maxSize - 1);

    printf("Inserted %d into Max Heap\n", val);

}

void deleteMax() {

    if (maxSize == 0) {

        printf("Max Heap is Empty!\n");

        return;

    }

    printf("Deleted root (Max): %d\n", maxHeap[0]);

    maxHeap[0] = maxHeap[maxSize - 1];

    maxSize--;

    heapifyDownMax(0);

}

void displayMax() {

    if (maxSize == 0) {

        printf("Max Heap is Empty!\n");

        return;

    }

    printf("Max Heap Array: ");

    for (int i = 0; i < maxSize; i++)

        printf("%d ", maxHeap[i]);

    printf("\n");

}

// MIN HEAP

int minHeap[MAX];

int minSize = 0;

void swapMin(int* a, int* b) {

    int temp = *a;

    *a = *b;

    *b = temp;

}

void heapifyUpMin(int index) {

    int parent = (index - 1) / 2;

    while (index > 0 && minHeap[index] < minHeap[parent]) {

        swapMin(&minHeap[index], &minHeap[parent]);

        index = parent;

        parent = (index - 1) / 2;

    }

}

void heapifyDownMin(int index) {

    int smallest = index;

    int left      = 2 * index + 1;

    int right = 2 * index + 2;

    if (left < minSize && minHeap[left] < minHeap[smallest])

        smallest = left;

    if (right < minSize && minHeap[right] < minHeap[smallest])

        smallest = right;

    if (smallest != index) {

        swapMin(&minHeap[index], &minHeap[smallest]);

        heapifyDownMin(smallest);

    }

}

void insertMin(int val) {

    if (minSize >= MAX) {

        printf("Min Heap is Full!\n");

        return;

    }

    minHeap[minSize] = val;

    minSize++;

    heapifyUpMin(minSize - 1);

    printf("Inserted %d into Min Heap\n", val);

}

void deleteMin() {

    if (minSize == 0) {

        printf("Min Heap is Empty!\n");

        return;

    }

    printf("Deleted root (Min): %d\n", minHeap[0]);

    minHeap[0] = minHeap[minSize - 1];

    minSize--;

    heapifyDownMin(0);

}

void displayMin() {

    if (minSize == 0) {

        printf("Min Heap is Empty!\n");

        return;

    }

    printf("Min Heap Array: ");

    for (int i = 0; i < minSize; i++)

        printf("%d ", minHeap[i]);

    printf("\n");

}

int main() { // MAIN

    printf("========== MAX HEAP ==========\n");

    insertMax(10);

    insertMax(20);

    insertMax(15);

    insertMax(40);

    insertMax(50);

    insertMax(25);

    displayMax();

    deleteMax();

    displayMax();

    printf("\n========== MIN HEAP ==========\n");

    insertMin(10);

    insertMin(20);

    insertMin(15);

    insertMin(40);

    insertMin(50);

    insertMin(25);

    displayMin();

    deleteMin();

    displayMin();

    return 0; }
