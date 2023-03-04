#include <stdio.h>

struct person{int id;char *name;int age;int height;int weight;};

void func(struct person arr[], int n){
    for(int j=1;j<n;j++){
        int i=j-1;
        struct person value = arr[j];
        while(i>=0 && value.height<arr[i].height){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=value;
    }
}

int main(){
    struct person p1 = {1, "Sokka", 15, 150, 45 };
    struct person p2 = {2, "Aang", 112, 137, 35};
    struct person p3 = {3, "Zuko", 16, 160, 50 };
    struct person p4 = {4, "Katara", 14, 145, 38 };
    struct person p5 = {5, "Toph", 12, 113, 30};

    struct person arr[5] = {
        p1,p2,p3,p4,p5
    };
    for (int i=0;i<5;i++){
        printf("%d ", arr[i].id);
    }printf("\n");
    func(arr, 5);
    for (int i=0;i<5;i++){
        printf("%d ", arr[i].id);
    }printf("\n");
    return 1;
}