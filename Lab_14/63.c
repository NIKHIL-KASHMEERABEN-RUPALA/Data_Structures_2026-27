#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Time intervals ne store karva mate struct ghoshana
struct Interval
{
    int start;
    int end;
};

struct Interval interval[MAX];
struct Interval stack[MAX];

int top = -1;

// Stack ni andar interval data insert karva mate push function (Base Guard sathe)
void push(struct Interval x)
{
    // Base Guard: Jo input ranges stack capacity karta vadhi jay toh protection aapse
    if (top >= MAX - 1)
    {
        printf("\nStack Overflow! Intervals khub j mota chhe.\n");
        exit(1);
    }
    stack[++top] = x;
}

// Intervals ne emna start time pramaney chadta kram (ascending order) ma arrange karva Bubble Sort
void sortIntervals(int n)
{
    int i, j;
    struct Interval temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // MCQ Trap: Sorting hammeša start time na check conditions pramaney j thashe
            if (interval[j].start > interval[j + 1].start)
            {
                temp = interval[j];
                interval[j] = interval[j + 1];
                interval[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    // Base Guard: Valid counting bounds check karo
    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of intervals entered.\n");
        return 1;
    }

    printf("Enter start and end of each interval:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &interval[i].start, &interval[i].end);
        
        // Base Guard: Logical interval checks (Start time kyarey End time thi motu na hovvu joie)
        if (interval[i].start > interval[i].end)
        {
            printf("Invalid Range! Start time, End time thi motu na hoi sake.\n");
            return 1;
        }
    }

    // Step 1: Intervals ne sort karo jethi overlapping groups line-sar mali sake
    sortIntervals(n);

    // Step 2: Pehla sorted interval block ne direct stack ma push karo
    push(interval[0]);

    // Step 3: Baki na badha intervals ne aagal vada element sathe merge karva check karo
    for (i = 1; i < n; i++)
    {
        // Jo aavto navo interval stack na top element ni vache overlapping thashe
        if (interval[i].start <= stack[top].end)
        {
            // Jo nava interval no ending time stack top na element karta vadhare hoy
            if (interval[i].end > stack[top].end)
            {
                // Stack top block no end point moti boundary pramaney extend karo
                stack[top].end = interval[i].end;
            }
        }
        // Non-overlapping interval check: Jo range aakhi alag padti hoy
        else
        {
            // Tene ek independent data entry tariqe stack ma push kari do
            push(interval[i]);
        }
    }

    // Final Stage: Badha merge thaya pachi na final exclusive blocks display karo
    printf("\nMerged Intervals:\n");
    for (i = 0; i <= top; i++)
    {
        printf("{%d,%d}\n", stack[i].start, stack[i].end);
    }

    return 0;
}