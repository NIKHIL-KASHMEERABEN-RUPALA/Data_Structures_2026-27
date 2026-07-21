#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define max 100

int top = -1;
char stack[max];

void push(char element){
    if(top >= max - 1){
        printf("\n Overflow condition ! ");
        return;
    }
    stack[++top] = element;
}

char pop(){
    if(top == -1){
        printf("\n Underflow condition ! ");
        return '#';
    }
    return stack[top--];
}

// Keeping your excellent logic intact!
bool isBalanced(char str[]){
    for (int i = 0 ; str[i] != '\0' ; i++){
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            push(ch);
        }
        else{
            char temp = pop();
            if(temp == '#'){
                return false;
            }
            if( (temp == '(' && ch != ')') ||
                (temp == '[' && ch != ']') ||
                (temp == '{' && ch != '}') )
            {
                return false;
            }
        }
    }
    if(top == -1){
        return true;
    }
    return false;
}

int main()
{
    int T;
    char str[max];

    printf("Enter number of test cases: ");
    if(scanf("%d", &T) != 1) return 0;

    while (T--)
    {
        // CRITICAL FIX: Reset the global stack pointer for every new test case
        top = -1; 
        
        scanf("%s", str);

        // Print 1 for true (balanced) and 0 for false (unbalanced)
        printf("%d\n", isBalanced(str));
    }
    return 0;
}