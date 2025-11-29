#include <stdio.h>
#include <stdlib.h>
int main()
{
    int file[50]; // To keep track of allocated blocks
    int i, startBlock, len, j, k, c;
    // Initialize all blocks as free (0 means free, 1 means allocated)
    for (i = 0; i < 50; i++)
        file[i] = 0;
    printf("\n--- Sequential File Allocation ---\n");
    while (1)
    {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d %d", &startBlock, &len);
        // Check if starting block and required length fit in disk
        if (startBlock < 0 || startBlock + len > 50)
        {
            printf("Error: Invalid block range! Try again.\n");
            continue;
        }
        // Check if required blocks are free
        k = 0;
        for (j = startBlock; j < (startBlock + len); j++)
        {
            if (file[j] == 0)
                k++;
        }
        // If all blocks are free
        if (k == len)
        {
            for (j = startBlock; j < (startBlock + len); j++)
            {
                file[j] = 1; // Mark as allocated
                printf("Block %d allocated.\n", j);
            }
            printf("File allocated successfully!\n");
        }
        else
        {
            printf("Error: The required blocks are not free!\n");
        }
        printf("\nDo you want to enter more files? (1 = Yes / 0 = No): ");
        scanf("%d", &c);
        if (c == 0)
            break;
    }
    printf("\n--- File Allocation Table (1 = Allocated, 0 = Free) ---\n");
    for (i = 0; i < 50; i++)
        printf("%d ", file[i]);
    printf("\n");
    return 0;
}