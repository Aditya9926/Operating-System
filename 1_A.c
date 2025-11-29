#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0; // Waiting time for the first process is 0
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1]; // Waiting time = previous waiting time + burst time of the previous process
    }
}
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
    }
}
void findAverageTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt);         // Calculate waiting time
    findTurnaroundTime(processes, n, bt, wt, tat); // Calculate turnaround time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}
int main()
{
    int processes[] = {1, 2, 3, 4};                   // Process IDs
    int n = sizeof(processes) / sizeof(processes[0]); // Number of processes
    int bt[] = {6, 8, 7, 3};                          // Burst times of processes
    findAverageTime(processes, n, bt);
    return 0;
}