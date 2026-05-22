#include<stdio.h>
#include<string.h>

int main(){

    int n;

    printf("\n Enter total names to compare :       ");
    scanf("%d",&n);

    char names[n][50];
    char temp[50];

    printf("\n Start entering the names :       ");
    for(int i = 0 ; i<n ; i++){
        scanf("%s",names[i]);
    }


    for(int i = 0 ; i<n-1 ; i++ ){
        for(int j = 0 ; j<n-i-1 ; j++){
            if(strcmp(names[j],names[j+1])>0){
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }

    printf("\n Names in Alphabetical Order: \n");

        for(int i = 0; i < n; i++)
        {
            printf("%s\n", names[i]);
        }







    return 0;   
}