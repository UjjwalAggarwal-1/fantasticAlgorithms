#include <stdio.h>

struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
typedef struct person * person;

void merge(person arr, int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    struct person L[n1], R[n2];
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

void mergeSort(person arr, int l, int r){
    if (l < r) {
    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l,m,r);
    }
}

int main(){

    struct person p1 = {1, "Sokka", 15, 150, 45 };
    struct person p2 = {2, "Aang", 112, 137, 35};
    struct person p3 = {3, "Zuko", 16, 160, 50 };
    struct person p4 = {4, "Katara", 14, 145, 38 };
    struct person p5 = {5, "Toph", 12, 113, 30};

    struct person arr[5] = {
        p1,p2,p3,p4,p5};
    for (int i=0;i<5;i++){
        printf("%d %s %d \n", arr[i].id, arr[i].name, arr[i].height);
    }printf("\n");
    mergeSort(arr, 0, 4);
    for (int i=0;i<5;i++){
        printf("%d %s %d \n", arr[i].id, arr[i].name, arr[i].height);
    }printf("\n");
    

    return 0;
}
