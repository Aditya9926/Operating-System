#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10], safeSeq[10];
    int count = 0;
    printf("\n--- Banker's Algorithm (Deadlock Avoidance) ---\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    printf("\nEnter Maximum Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("\nEnter Available Resources (for each type):\n");
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);
    // Calculate Need Matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    for (i = 0; i < n; i++)
        finish[i] = 0;
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safeSeq[y++] = i;
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                }
            }
        }
    }
    int safe = 1;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            safe = 0;
            break;
        }
    }
    if (safe)
    {
        printf("\n System is in a SAFE STATE.\nSafe Sequence: ");
        for (i = 0; i < n - 1; i++)
            printf("P%d -> ", safeSeq[i]);
        printf("P%d\n", safeSeq[n - 1]);
    }
    else
    {
        printf("\nSystem is in DEADLOCK (Unsafe State)!\n");
    }
    return 0;
}