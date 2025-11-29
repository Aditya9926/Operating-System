#include <stdio.h>
int main()
{
    int file[50], start, length, i, j, k, c;
    // Initialize all blocks as free
    for (i = 0; i < 50; i++)
        file[i] = 0;
    printf("\n--- Linked File Allocation ---\n");
    while (1)
    {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d %d", &start, &length);
        if (start < 0 || start >= 50 || (length <= 0))
        {
            printf("Invalid input! Try again.\n");
            continue;
        }
        j = 0;
        for (i = start; i < 50 && j < length; i++)
        {
            if (file[i] == 0)
            {
                file[i] = 1;
                printf("Block %d allocated -> ", i);
                j++;
            }
        }
        if (j == length)
        {
            printf("File allocated successfully!\n");
        }
        else
        {
            printf("\nInsufficient free blocks. Allocation failed!\n");
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