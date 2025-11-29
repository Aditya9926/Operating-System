#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[])
{
    int pos, temp;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (priority[j] < priority[pos])
            {
                pos = j;
            }
        }
        // Swap burst time and process ID to arrange by priority
        temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = processes[i];
        processes[i] = processes[pos];
        processes[pos] = temp;
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void findAverageTime(int processes[], int n, int bt[], int priority[])
{
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt, priority);
    findTurnaroundTime(processes, n, bt, wt, tat);
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], priority[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}
int main()
{
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int bt[] = {6, 8, 7, 3};
    int priority[] = {2, 1, 4, 3}; // Lower number means higher priority
    findAverageTime(processes, n, bt, priority);
    return 0;
}