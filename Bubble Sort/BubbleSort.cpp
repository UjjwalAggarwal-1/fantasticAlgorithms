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
    for(int i =1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    //output array
    for(int i =0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
}