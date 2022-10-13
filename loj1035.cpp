#include<bits/stdc++.h>
#include"Sieve.h"
using namespace std;
#define rang 1000
/*/ define the all primes in 300
int pri[62] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59, 61, 67 ,71 ,73 ,79, 83, 89, 97,
101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
*/
///This section we calculate the prime number from the others code to calculate prime in rang value you given autometically no need to add it menually
vector<int> pri = SIEVE(rang);
map<int,vector<int>> n_pri;

/// this section find all factiorial prime and also
void find_factorial_prime(){
    n_pri[2].push_back(2);
    n_pri[3].push_back(2);
    n_pri[3].push_back(3);
    /// This for we calculate the prime factorial for every value of the range 4 to 100.
    for(int i = 4; i<= rang; i++){
        int tem = i;
        for(int j = 0; pri[j]*pri[j]<=i; j++){
            if(tem%pri[j]==0){
                while(tem%pri[j]==0){
                    tem/=pri[j];
                    n_pri[i].push_back(pri[j]);
                }

            }

        }
        if(tem>1)
            n_pri[i].push_back(tem);
       ///This section we just inset pevivous vector into the curent value of factoreial.
       //for(int j = 0; j<n_pri[i-1].size(); j++)
       //   n_pri[i].push_back(n_pri[i-1][j]);
       ///This section use the vector insert(from where to insert, begin of the insert value, end of the insert vector);
         n_pri[i].insert(n_pri[i].end(), n_pri[i-1].begin(), n_pri[i-1].end());

    }



}

void find_pri_factor(int n){
    map<int,int>res;
    map<int,int>::iterator it,last;
    for(int i = 0; i<n_pri[n].size(); i++)
       res[n_pri[n][i]]++;

    cout<<n<<" = ";
    for(it = res.begin(),last = res.end(),last--; it!= res.end(); it++){
        if(it->second >0 && it != last)
            cout<<it->first<<" ("<<it->second<<") * ";
        else
            cout<<it->first<<" ("<<it->second<<")"<<endl;
    }
}
int main(){

    find_factorial_prime();
    int t,val;
    cin>>t;
    for(int i = 1; i<=t; i++){
        cin>>val;
        cout<<"Case "<<i<<": ";
        find_pri_factor(val);

    }
}
add