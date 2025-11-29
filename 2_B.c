#include <stdio.h>
int main()
{
    int file[50], indexBlock[50], i, n, index, c, block;
    // Initialize all blocks as free (0)
    for (i = 0; i < 50; i++)
        file[i] = 0;
    printf("\n--- Indexed File Allocation ---\n");
    while (1)
    {
        printf("\nEnter the index block: ");
        scanf("%d", &index);
        if (index < 0 || index >= 50)
        {
            printf("Invalid index block! Try again.\n");
            continue;
        }
        if (file[index] == 1)
        {
            printf("Index block already allocated!\n");
            continue;
        }
        file[index] = 1; // Allocate index block
        printf("Enter the number of blocks to be allocated for the file: ");
        scanf("%d", &n);
        printf("Enter %d block numbers:\n", n);
        for (i = 0; i < n; i++)
            scanf("%d", &indexBlock[i]);
        // Check if blocks are free
        for (i = 0; i < n; i++)
        {
            if (file[indexBlock[i]] == 1)
            {
                printf("Block %d already allocated. Allocation failed!\n", indexBlock[i]);
                n = -1;
                break;
            }
        }
        if (n != -1)
        {
            for (i = 0; i < n; i++)
            {
                file[indexBlock[i]] = 1;
            }
            printf("File allocated successfully!\n");
            printf("Index Block %d -> ", index);
            for (i = 0; i < n; i++)
                printf("%d ", indexBlock[i]);
            printf("\n");
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