#include<bits/stdc++.h>
using namespace std;
#define rang 101
int pri[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59, 61, 67 ,71 ,73 ,79, 83, 89, 97};


void find_factorial_prime(int val, int n_pri[rang][rang]){
    for(int i = 2; i<=val; i++){
        int tem = i;
        for(int j = 0; pri[j]<=i; j++){
            if(tem%pri[j]==0)
                while(tem%pri[j]==0){
                    tem/=pri[j];
                    n_pri[i][pri[j]]++;
                }
        /*    if(tem>1)
               n_pri[i][i]++;*/
        }


    }
    int p,c;
    cout<<pri[p]<<" : ";
    for(p = 0; p<25; p++){
        int c = 0;
       // cout<<pri[p]<<"= ";
        for(int i = 2; i<rang; i++){
           if(n_pri[i][pri[p]] >0)
            cout<<n_pri[i][pri[p]]<<endl;
        }
       // cout<<"("<<c<<")";
    }
    cout<<endl;
}

int main(){
    int t,val;
    cin>>t;
    for(int i = 1; i<=t; i++){
        int n_pri[rang][rang];
        cin>>val;
        find_factorial_prime(val, n_pri);
    }
}
