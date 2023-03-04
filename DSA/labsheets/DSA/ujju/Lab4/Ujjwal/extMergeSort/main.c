// 0,Raymond Mcwilliams,93,80,146
// 1,John Collins,87,64,268
// 2,Janet Avalos,91,77,140
// 3,Ben Noland,78,61,151

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000
struct person{int id;char name[20];int age;int height;int weight;};
typedef struct person person;
typedef struct person * PERSON;

void print(char* str){
    printf("%s\n",str);
}

void merge(person arr[], int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    person L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].height <= R[j].height) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(person arr[], int l, int r){
    if (l < r) {
    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l,m,r);
    }
}


int main(){
    FILE *f1 = fopen("dat7578440.csv", "r");
    if (f1 == NULL){printf("Error opening file");return 1;}
    int count =0;
    long tally = 7578440;
    while(tally>0){
        count++;
        char filename[15] = "op/sorted";
        char ind[3] ;
        sprintf(ind,"%d",count);
        strcat(filename,ind);
        strcat(filename,".csv");
        printf("%s\n",filename);
        FILE *f2 = fopen(filename, "w");
        if (f2 == NULL){printf("Error opening file2");return 1;}

        int actual = 0;
        person arr[N];
        for (int i =0;i<N;i++){
            fscanf(f1,"%d,%[^,],%d,%d,%d\n",&arr[i].id,arr[i].name,&arr[i].age, &arr[i].weight, &arr[i].height);
            tally--;
            actual++;
            if (!tally){
                break;
            }
        }
        mergeSort(arr,0,actual-1);
         for (int i =0;i<actual;i++){
            fprintf(f2, "%d,%s,%d,%d,%d\n", arr[i].id, arr[i].name, arr[i].age,arr[i].weight,arr[i].height);
         } 

        fclose(f2);
    }
    fclose(f1);
    return 0;
}