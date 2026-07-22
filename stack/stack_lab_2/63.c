#include<stdio.h>
#include<string.h>

struct Interval {
    int start;
    int end;
};

struct Interval interval[100];
struct Interval stack[100];

int top = -1;

void push(struct Interval element){
    stack[++top] = element;
}

void sortElements(int n){
    
}