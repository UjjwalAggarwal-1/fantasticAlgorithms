#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n = 109;

    // array of range(n+1)
    int primes[n+1]={0};
    for(int i=0;i<=n;i++)
        primes[i]=i;
    

    //either nested or while loop this is BS
    // for(int i=2, j=i*i;j>=i*i && i<=10; j+=i){
    //     if(primes[j]==0)
    //         continue;
    //     if(j>=100){
    //         i++;
    //         j=i*i;
    //         primes[j]=0;}
    //     else
    //         primes[j]=0;
    // }

    for(int i=2;i<=sqrt(n);i++){
        if(primes[i*i]==0)
            continue;
        for (int j=i*i;j<=n;j+=i)
            primes[j]=0; 
    }


    //just output
    for(int i=2;i<=n;i++){
        if(primes[i]!=0)
            cout<<primes[i]<<" ";
        }
    cout<<endl;
    return 0;
}