#include <stdio.h>
#include <stdlib.h>
#define N 5 // Number of philosophers
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int state[N];
int phil[N] = {0, 1, 2, 3, 4};
void wait(int *s) { --(*s); }
void signal(int *s) { ++(*s); }
void test(int i);
void take_fork(int i);
void put_fork(int i);
void philosopher(int i);
void eat(int i);
void think(int i);
int mutex = 1;                     // Binary semaphore
int fork_sem[N] = {1, 1, 1, 1, 1}; // Fork semaphores
void main()
{
    int choice;
    printf("\n--- Dining Philosophers Problem Simulation ---\n");
    printf("1. Start simulation\n2. Exit\n");
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < N; i++)
                philosopher(i);
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
void philosopher(int i)
{
    think(i);
    take_fork(i);
    eat(i);
    put_fork(i);
}
void take_fork(int i)
{
    wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", i + 1);
    if (fork_sem[i] == 1 && fork_sem[(i + 1) % N] == 1)
    {
        wait(&fork_sem[i]);
        wait(&fork_sem[(i + 1) % N]);
        state[i] = EATING;
        printf("Philosopher %d takes forks %d and %d and starts EATING\n", i + 1, i + 1, (i + 1) % N + 1);
    }
    else
    {
        printf("Philosopher %d cannot eat now, waiting...\n", i + 1);
    }
    signal(&mutex);
}
void put_fork(int i)
{
    wait(&mutex);
    state[i] = THINKING;
    signal(&fork_sem[i]);
    signal(&fork_sem[(i + 1) % N]);
    printf("Philosopher %d puts down forks %d and %d and starts THINKING\n", i + 1, i + 1, (i + 1) % N + 1);
    signal(&mutex);
}
void eat(int i)
{
    printf("Philosopher %d is EATING\n", i + 1);
}
void think(int i)
{
    printf("Philosopher %d is THINKING\n", i + 1);
}