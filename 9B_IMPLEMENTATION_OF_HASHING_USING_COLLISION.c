#include <stdio.h>
#define SIZE 10
int main()
{
    int linear[SIZE], quadratic[SIZE];
    int n, key, i, j, index;
    for(i = 0; i < SIZE; i++)
    {
        linear[i] = -1;

        quadratic[i] = -1;
    }
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter keys:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &key);
        /* Linear Probing */
        index = key % SIZE;
        while(linear[index] != -1)
            index = (index + 1) % SIZE;
        linear[index] = key;
        /* Quadratic Probing */
        index = key % SIZE;
        j = 1;
        while(quadratic[index] != -1)
        {
            index = (key % SIZE + j * j) % SIZE;
            j++;
        }
        quadratic[index] = key;
    }

    printf("\nHash Table using Linear Probing:\n");
    for(i = 0; i < SIZE; i++)
        printf("%d --> %d\n", i, linear[i]);
    printf("\nHash Table using Quadratic Probing:\n");
    for(i = 0; i < SIZE; i++)
        printf("%d --> %d\n", i, quadratic[i]);
    return 0;
}
