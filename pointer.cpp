#include<iostream>

using namespace std;



int sum(int *ar, int n){
    int sum=0;
    for (int i=0;i<n;i++){
        sum = sum + *(ar + i);
    }return sum;
}


int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int ans = sum(ar,n);
    cout<<ans;
}