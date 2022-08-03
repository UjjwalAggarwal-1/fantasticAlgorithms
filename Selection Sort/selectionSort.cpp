#include <iostream>

int main(){

    //input array
    int n;
    std::cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        std::cin>>arr[i];
    }

    // sort
    for(int i =0;i<n-1;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    //output array
    for(int i =0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
}