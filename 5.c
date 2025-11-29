#include <stdio.h>
int main()
{
    int n, m; // n = number of processes, m = number of resources
    int allocation[10][10], request[10][10];
    int available[10], finish[10];
    int i, j, k, flag;
    printf("\n--- Resource Allocation Graph (Deadlock Detection) ---\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    printf("\nEnter Request Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &request[i][j]);
    printf("\nEnter Available Resources (for each type):\n");
    for (j = 0; j < m; j++)
        scanf("%d", &available[j]);
    for (i = 0; i < n; i++)
        finish[i] = 0; // process not yet completed
    int deadlockCount = 0;
    for (k = 0; k < n; k++)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int canRun = 1;
                for (j = 0; j < m; j++)
                {
                    if (request[i][j] > available[j])
                    {
                        canRun = 0;
                        break;
                    }
                }
                if (canRun)
                {
                    for (j = 0; j < m; j++)
                        available[j] += allocation[i][j];
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
        if (flag == 0)
            break;
    }
    printf("\nProcess Completion Status:\n");
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            printf("Process P%d is in deadlock.\n", i);
            deadlockCount++;
        }
    }
    if (deadlockCount == 0)
        printf("\nNo Deadlock Detected.\n");
    else
        printf("\n Deadlock Detected among %d processes.\n", deadlockCount);
    return 0;
}