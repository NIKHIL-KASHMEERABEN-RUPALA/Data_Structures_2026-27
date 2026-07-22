#include <stdio.h>

#define MAX 100

//--------------------------------------
// Structure for Interval
//--------------------------------------
struct Interval
{
    int start;
    int end;
};

struct Interval interval[MAX];
struct Interval stack[MAX];

int top = -1;

//--------------------------------------
// Push Interval
//--------------------------------------
void push(struct Interval x)
{
    stack[++top] = x;
}

//--------------------------------------
// Bubble Sort according to start time
//--------------------------------------
void sortIntervals(int n)
{
    int i, j;
    struct Interval temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (interval[j].start > interval[j + 1].start)
            {
                temp = interval[j];
                interval[j] = interval[j + 1];
                interval[j + 1] = temp;
            }
        }
    }
}

//--------------------------------------
// Main Function
//--------------------------------------
int main()
{
    int n, i;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    printf("Enter start and end of each interval:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &interval[i].start, &interval[i].end);
    }

    // Step 1 : Sort intervals
    sortIntervals(n);

    // Step 2 : Push first interval
    push(interval[0]);

    // Step 3 : Merge remaining intervals
    for (i = 1; i < n; i++)
    {
        // Overlapping interval
        if (interval[i].start <= stack[top].end)
        {
            if (interval[i].end > stack[top].end)
            {
                stack[top].end = interval[i].end;
            }
        }
        // Non-overlapping interval
        else
        {
            push(interval[i]);
        }
    }

    // Display Result
    printf("\nMerged Intervals:\n");

    for (i = 0; i <= top; i++)
    {
        printf("{%d,%d}\n", stack[i].start, stack[i].end);
    }

    return 0;
}