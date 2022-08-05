#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cout<<"Upto What number: ";
    cin>>n;
    int primes[n+1]={0};
    for(int i=2;i<=n;i++)
        primes[i]=i;
    int count =0;
    primes[1]=0;
    count++;
    for(int i=2;i<=sqrt(n);i++){
        if(primes[i*i]==0)
            continue;
        for (int j=i*i;j<=n;j+=i){
            if(primes[j]!=0){
                primes[j]=0;count++;
            }
        }
    }
    cout<<"sprt of n : "<<sqrt(n)<<endl;
    cout<<"n-count : number of primes : "<<n-count<<endl;
    int onlyPrimes[n-count]={0};
    for(int i=1,j=0;i<=n;i++){
        if(primes[i]!=0){
            onlyPrimes[j]=primes[i];
            j++;
        }
    }
    cout<<"Primes : ";
    for(int i=0;i<=n-count-1;i++)
        cout<<onlyPrimes[i]<<" ";
    cout<<endl;
    cout<<"Prime Factors : ";
    for (int i=0;i<n-count;i++){
        if(n%onlyPrimes[i]==0)
            cout<<onlyPrimes[i]<<" ";
    }
    cout<<endl;
}