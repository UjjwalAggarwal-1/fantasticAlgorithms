#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person Person;

struct person{int id;char *name;int age;int height;int weight;};


// int main(){
//     int n = 10;
//     FILE* fptr;
//     char name[100];
//     int id, h, w, a;
//     int i = 0; 
//     Person arr[n];
    
//     fptr=fopen("../dat1000.csv","r");
//     if (fptr==NULL){
//         printf("File not found");
//         return 0;
//     }

//     while(i<n){
//         i++;
//         printf("%d ", i);
//         fscanf(fptr,"%d,%s,%d,%d,%d\n",&id,name,&a, &h, &w);
//         printf("%d\n", id);
//         Person p={id, name, a, h, w};
//         arr[i-1]=p;
//     }
//     fclose(fptr);

//     for (int i = 0; i<10;i++){
//         printf("%d %s %d %d %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
//     }printf("\n");

//     return 0;
// }

void func(struct person arr[], int n){
    for(int j=1;j<n;j++){
        int i=j-1;
        struct person value = arr[j];
        while(i>=0 && strcmp(value.name,arr[i].name)<0){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=value;
    }
}


int main(){
    int n = 1000;
    FILE* fptr;

    int i = 0; 
    Person* arr = (Person*)malloc(n*sizeof(Person));
    
    fptr=fopen("../dat1000.csv","r");
    if (fptr==NULL){
        printf("File not found\n");
        return 0;
    }

    while(i<n){
        // printf("%d ", i);

        arr[i].name = malloc(100*sizeof(char));
        fscanf(fptr,"%d,%[^,],%d,%d,%d\n",&arr[i].id,arr[i].name,&arr[i].age, &arr[i].height, &arr[i].weight);
        // printf("%d\n", arr[i].age);
        i++;
    }
    fclose(fptr);

    func(arr, n);

    for (int i = 0; i<n;i++){
        printf("%d %s %d %d %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }printf("\n");

    return 0;
}