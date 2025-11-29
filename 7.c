#include <stdio.h>
#include <stdlib.h>
int mutex = 1; // Binary semaphore for mutual exclusion
int full = 0;  // Counts filled slots
int empty;     // Counts empty slots
int x = 0;     // Item counter
// Function prototypes
void producer();
void consumer();
void wait(int *s);
void signal(int *s);
int main()
{
    int n;
    int choice;
    printf("\n--- Producer-Consumer Problem Simulation using Semaphores ---\n");
    printf("Enter the size of buffer: ");
    scanf("%d", &empty);
    printf("\n1. Produce an item");
    printf("\n2. Consume an item");
    printf("\n3. Exit");
    while (1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full! Producer waiting...\n");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty! Consumer waiting...\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
void wait(int *s)
{
    --(*s);
}
void signal(int *s)
{
    ++(*s);
}
void producer()
{
    wait(&mutex);
    wait(&empty);
    x++;
    printf("Producer produces item %d\n", x);
    signal(&full);
    signal(&mutex);
}
void consumer()
{
    wait(&mutex);
    wait(&full);
    printf("Consumer consumes item %d\n", x);
    x--;
    signal(&empty);
    signal(&mutex);
}