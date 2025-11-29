#include <stdio.h>
int main()
{
    int i, j, n, frames, pages[30], temp[10], flag = 0, pageFaults = 0;
    printf("\n--- FIFO Page Replacement Algorithm ---\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    for (i = 0; i < frames; i++)
        temp[i] = -1;
    j = 0; // Points to the oldest page
    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (int k = 0; k < frames; k++)
        {
            if (temp[k] == pages[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            temp[j] = pages[i];
            j = (j + 1) % frames;
            pageFaults++;
        }
        printf("%d\t", pages[i]);
        for (int k = 0; k < frames; k++)
        {
            if (temp[k] != -1)
                printf("%d ", temp[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
