#include <stdio.h>
#include <stdlib.h>

typedef struct node * NODE;
struct node{
    int ele;
    NODE next;
};

typedef struct linked_list * LIST;
struct linked_list{
    int count;
    NODE head;
};



int main(){

    return 0;
}