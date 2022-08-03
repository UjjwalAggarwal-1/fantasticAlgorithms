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
    for (int i=1;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }

    //output array
    for(int i =0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
}