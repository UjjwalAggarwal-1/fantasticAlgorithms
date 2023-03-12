#include <stdio.h>
#include <stdlib.h>

#define N 14
#define S sizeof(int)


void merge(int A[], int l, int m, int h){
    int s1 = l;
    int e1 = m;
    int s2 = m+1;
    int e2 = h;

    int i = s1;
    int j = s2;
    int n2= (h-l+1);
    int * AuxA = (int*) malloc(n2*S);
    int k = 0;
    // printf(">> %d %d %d %d %d\n", s1, e1, s2, e2, n2);
    while(i<=e1 && j<=e2){
        // printf(">>>> %d %d\n", i,j);
        if (A[i]<A[j])
            AuxA[k++]=A[i++];
        else
            AuxA[k++]=A[j++];

        // for (int z=l;z<n2;z++)
        //     printf("e%d ",AuxA[z]);
        //     printf("nnn\n");
    
    }

    while (i<=e1){
        // printf(">>>i> %d %d\n", i,j);
        AuxA[k++]=A[i++];
    }
    while (j<=e2){
        // printf(">>>j> %d %d\n", i,j);
        AuxA[k++]=A[j++];
    }
    k=0;
    for (i=l;i<=h;i++){
        A[i] = AuxA[k++];
    }

    return;
}

void mergeSort(int A[], int n){
    int s =0;
    for (s = 2; s<=n*2; s *=2){
        for (int i = 0; i<n; i+=s){
            int achu = s>n-i?n-i:s;
            // printf("%d %d %d\n", i, s, achu);
            merge(A, i, i+s/2 -1,i+achu-1);
            // for (int z=0;z<n;z++)
            // printf("%d ",A[z]);
            // printf("\n");
        }
    }

    // if (s/2<n){
    //     merge(A,0,s/2-1,n-1);
    // }


    return;
}

int main(){
    // int n = 10;

    int A[N]= {1,2,33,5,9,8,0,7,30,15,12,11,55,20};
    // int A[N] = {1,2,6,7,3,4,5,9}; 
    for(int i=0;i<N;i++) printf("%d ", A[i]); printf("\n");
    // merge(A, 0,N/2 -1,N-1);
    mergeSort(A,N);
    // merge(A, 0,0,1);
    // merge(A,2,2,3);
    // merge(A,4,4,5);
    // merge(A,6,6,7);
    for(int i=0;i<N;i++) printf("%d ", A[i]); printf("\n");

    return 0;
}