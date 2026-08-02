#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node*next;
};

struct Node*front = NULL;
struct Node*rear = NULL;