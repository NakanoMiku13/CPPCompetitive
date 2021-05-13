#include<bits/stdc++.h>
using namespace std;
int n,a,c;
int main(){
    cin>>n;
    n*=3;
    for(auto i=0;i<n;i++){
        cin>>a;
        c+=a;
        cout<<c<< " ";
    }
    if(c==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}