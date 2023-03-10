#include "linkedlist.h"
#include <stdio.h>
#include <string.h>

static node *create_node_for_list(process p);
// Check header files for documentation/ function description
process_linked_list *create_empty_process_linked_list() {
    // COMPLETE
    process_linked_list * epll = (process_linked_list*) malloc(sizeof(process_linked_list));
    epll->size = 0;
    epll -> head = NULL;
    return epll;
}

bool add_first_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, 0, p);
}

bool add_last_to_linked_list(process_linked_list *list, process p) {
    // printf("hi\n");
    return add_at_index_linked_list(list, list->size, p);
}

void copy_process(process* np, process p){
    np->name =(char*) malloc(5*sizeof(char));
    strcpy(np->name, p.name);
    np->pid = p.pid;
    np->arrival = p.arrival;
    np->cpu_burst = p.cpu_burst;
    np->turnaround = p.turnaround;
    np->wait = p.wait;
    np->remaining_time = p.remaining_time;
    return;
}

bool add_at_index_linked_list(process_linked_list *list, size_t index, process p) {
   // COMPLETE
    if(list->size<index){
        return false;
    }
    if (list->size==0){
    // printf("hi\n");
        node * nnode = malloc(sizeof(node));
        process* np = malloc(sizeof(process));
        copy_process(np, p);
        nnode->next = NULL;
        nnode->previous = NULL;
        nnode->process = np;
        list->head = nnode;
        list->size++;
        return true;
    }
    node * onode = list->head;
    for(int i=0;i<index-1;i++){
        onode = onode->next;
    }
    // printf("hi from not 0 size%d\n", onode->process->pid);
    node * nnode = malloc(sizeof(node));
    nnode->next = onode->next;
    if (onode->next!=NULL) onode->next->previous = nnode; //this would be for last element
    onode->next = nnode;
    nnode->previous = onode;
    process* np = malloc(sizeof(process));
    copy_process(np, p);
    nnode->process = np;
    list->size++;
    return true;
}

bool remove_first_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
   // COMPLETE
   node * temp = list->head;
   if (list->head->next != NULL) list->head->next->previous = NULL;
   list->head = list->head->next;
   p = temp->process;
    free(temp);
   list->size--;
   return true;
}

bool remove_last_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
   // COMPLETE
   node * temp = list->head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->previous->next = NULL;
    p = temp->process;
    free(temp);
    list->size--;
    return true;
}

size_t get_size_linked_list(process_linked_list *list) {
    return list->size;
}

void print_linked_list(process_linked_list *list) {
    if(list==NULL) {printf("DNExist\n"); return;}
    if(list->head==NULL) {printf("empTy\n"); return;}
    node *tracker = list->head;
    for (int i = 0; i < list->size; ++i) {
        printf("%d =>", tracker->process->pid);
        tracker = tracker->next;
    }
    printf("\n");
}

static node *create_node_for_list(process p) {
    process *to_add_process = malloc(sizeof(process));
    if (!to_add_process) {
        return NULL;
    }
    *to_add_process = p;
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        return NULL;
    }
    new_node->process = to_add_process;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}


void destroy_linked_list(process_linked_list *list) {
    node *current = list->head;
    for (int i = 0; i < list->size; ++i) {
        node *next = current->next;
        free(current->process);
        current = next;
    }
    free(list->head);
    // process_linked_list* temp = list;
    free(list);
    // printf("freed%p\n", list);
    // list = NULL;
    // printf("HOHL%p\n", list);

    return;
}
