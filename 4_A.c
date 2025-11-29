#include <stdio.h>
int main()
{
    int blockSize[10], processSize[10], i, j, nb, np, allocation[10];
    printf("\n--- Worst Fit Memory Allocation ---\n");
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter size of each block:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter size of each process:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &processSize[i]);
    for (i = 0; i < np; i++)
        allocation[i] = -1;
    for (i = 0; i < np; i++)
    {
        int worstIdx = -1;
        for (j = 0; j < nb; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    printf("\nProcess\tProcess Size\tBlock Allocated\n");
    for (i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}