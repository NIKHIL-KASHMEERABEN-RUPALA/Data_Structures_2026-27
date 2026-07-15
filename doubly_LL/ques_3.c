#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Song{
    char name[100];
    struct Song*prev;
    struct Song*next;
};

struct Song *createSong(char name_of_song[]){
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong , name_of_song);
    newSong->prev = NULL;
    newSong->next = NULL;
    return newSong;
}

