#include <stdio.h>
int main()
{
    int i, j, k, n, frames, pages[30], temp[10], counter[10];
    int flag1, flag2, pos, pageFaults = 0, min;
    printf("\n--- LRU Page Replacement Algorithm ---\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
        counter[i] = 0;
    }
    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++)
    {
        flag1 = flag2 = 0;
        for (j = 0; j < frames; j++)
        {
            if (temp[j] == pages[i])
            {
                counter[j] = i + 1; // Update usage time
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (j = 0; j < frames; j++)
            {
                if (temp[j] == -1)
                {
                    temp[j] = pages[i];
                    counter[j] = i + 1;
                    flag2 = 1;
                    pageFaults++;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            min = counter[0];
            pos = 0;
            for (j = 1; j < frames; j++)
            {
                if (counter[j] < min)
                {
                    min = counter[j];
                    pos = j;
                }
            }
            temp[pos] = pages[i];
            counter[pos] = i + 1;
            pageFaults++;
        }
        printf("%d\t", pages[i]);
        for (j = 0; j < frames; j++)
        {
            if (temp[j] != -1)
                printf("%d ", temp[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}