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

LIST createNewList(){
    LIST l = (LIST) malloc(sizeof(struct linked_list));
    l->count = 0;
    l->head = (NODE) malloc(0*sizeof(struct node));
    return l;
}

NODE createNewNode(int value){
    NODE n = (NODE) malloc(sizeof(struct node));
    n->next = (NODE) malloc(0*sizeof(struct node));
    n->ele = value;
    return n;
}

void insertAfter(int ele, NODE n, LIST l){

    if (l->head == NULL) {
        l->head = n;
        l->count++;
        n->next = NULL;
        return;
    };

    NODE now = l->head;
    int fnd = 0;
    while (now){
        if (now->ele = ele){
            n->next = now->next;
            now->next = n;
            l->count++;
            fnd = 1;
            break;
        }
        now = now->next;
    };

    if (!fnd){
        while (now->next){
          now = now->next;
        };
        l->count++;
        now->next = n;
        n->next = NULL;
    }
    return;
}

int main(){

    return 0;
}