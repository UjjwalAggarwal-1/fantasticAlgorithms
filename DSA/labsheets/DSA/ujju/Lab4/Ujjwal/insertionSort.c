#include <stdio.h>

void insertInOrder(int aj, int A[], int j){
    // for (int i =j-1; i>=0; i--){
    //     if (A[i]>A[i+1]) {
    //         int temp = A[i+1];
    //         A[i+1] = A[i];
    //         A[i] = temp;
    //     }
    // }
    int i=j-1;
    while(i>=0 && aj<A[i]){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=aj;
}

void insertionSort(int A[], int n){
    for(int j=1;j<n;j++){
        insertInOrder(A[j],A,j);
    }
}
