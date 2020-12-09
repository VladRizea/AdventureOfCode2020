#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


int check(int k,int n, long long V[1001]){

for(int i=k-25;i<=k-1;i++){
        for(int j=k-25;j<=k-1;j++){
            if(i != j && V[i] + V[j] == V[k]) return 1;
}
}
return 0;

}

int checkSum(int k,int n, long long V[1001]){

long long S=0,j, mini, maxi = 0;

for(int i=1;i<k;i++){
        S=V[i];
        j=i+1;
        mini = V[i];
        while(S<V[k]){
            S = S + V[j];
            j++;
        }
        if(S == V[k]) {
        for(int h = i ; h<=j-1;h++){
            if(V[h] > maxi) maxi = V[h];
            if(V[h] < mini) mini = V[h];
        }
        cout<<"Test 2: "<<mini+maxi;
      }
}
return 0;

}

int main()
{

long long V[1001];
int inva = 0, n=1;

ifstream in("intrare.in");

while(in>>V[n]){
    n++;
}
for(int i=25;i<n;i++)
    if (check(i,n,V) == 0){inva = i; cout<<"TEST 1: "<<V[i]<<endl;}

checkSum(inva,n,V);

return 0;

}


