#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct occupant{
    char name[20];
    int age;
    char address[30];

};
typedef struct occupant * Occupant;

struct hotel{
    char name[20];
    char address[30];
    int no_occupied_rooms;
    Occupant occupants;

};
typedef struct hotel * Hotel;

void assign_first_available(Hotel h, Occupant o){
    Occupant os = h->occupants;
    int n = h->no_occupied_rooms;
    h->no_occupied_rooms++;
    os = realloc(os, (h->no_occupied_rooms)*sizeof(struct occupant));
    if (os==NULL){
        printf("NULL\n"); return;
    }
    strcpy((os+n)->name, (o->name));
    (os+n)->age = (o->age);
    strcpy((os+n)->address, (o->address));
    h->occupants = os;
}

void assign_first(Hotel h, Occupant o){
    h->no_occupied_rooms++;
    h->occupants = realloc(h->occupants, (h->no_occupied_rooms)*sizeof(struct occupant));
    if (h->occupants==NULL){
        printf("NULL\n"); return;
    }
    for (int i =h->no_occupied_rooms;i>=0;i--){
        // *(h->occupants+i+1) = *(h->occupants+i);
        strcpy((h->occupants+i+1)->name, (h->occupants+i)->name);
        (h->occupants+i+1)->age = (h->occupants+i)->age;
        strcpy((h->occupants+i+1)->address, (h->occupants+i)->address);
    }
    // *h->occupants = *o;
    strcpy((h->occupants)->name, (o->name));
    (h->occupants)->age = (o->age);
    strcpy((h->occupants)->address, (o->address));
}

void delete_at_i(Hotel h, int iks){
    for (int i =iks;i<=h->no_occupied_rooms;i++){
        strcpy((h->occupants+i)->name, (h->occupants+i+1)->name);
        (h->occupants+i)->age = (h->occupants+i+1)->age;
        strcpy((h->occupants+i)->address, (h->occupants+i+1)->address);
    }
    h->no_occupied_rooms--;
}

int main(){

    Hotel h = (Hotel) malloc(sizeof(struct hotel));
    if (h==NULL){
        printf("NULL\n"); return -1;
    }
    strcpy(h->name,"Grand Hotel");
    strcpy(h->address, "PITSB");
    h->no_occupied_rooms = 0;
    h->occupants = (Occupant) malloc(0*sizeof(struct occupant));
    if (h->occupants==NULL){
        printf("NULL\n"); return -1;
    }
    printf("%p\n", h);
    printf("%s\n", h->name);
    printf("%s\n", h->address);
    printf("%d\n", h->no_occupied_rooms);
    printf("%p\n", h->occupants);
    printf("\n");

    Occupant new_o =(Occupant) malloc(sizeof(struct occupant));
    if (new_o==NULL){
        printf("NULL\n"); return -1;
    }
    strcpy(new_o->name, "new");
    new_o->age = 20;
    struct occupant o2 = {"another one", 55, "over there"};
    assign_first_available(h,new_o);
    assign_first_available(h,&o2);
    assign_first_available(h,new_o);
    assign_first_available(h,&o2);
    for (int i =0;i<h->no_occupied_rooms;i++) printf("%d %s %d\n",i, (h->occupants+i)->name, (h->occupants[i]).age);
    printf("\n");
    struct occupant o3 = {"not the same one", 35, "over there"};
    assign_first(h,&o3);
    assign_first(h,&o3);
    for (int i =0;i<h->no_occupied_rooms;i++) printf("%d %s %d\n",i, (h->occupants+i)->name, (h->occupants[i]).age);
    printf("\n");
    
    delete_at_i(h, 2);
    delete_at_i(h, 2);
    for (int i =0;i<h->no_occupied_rooms;i++) printf("%d %s %d\n",i, (h->occupants+i)->name, (h->occupants[i]).age);

    
    return 1;
}