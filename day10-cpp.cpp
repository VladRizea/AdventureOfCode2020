#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int n,k,as,ev, suma = 0 ,st[100];



int checkin(int n, int &S, int &c1, int&c3, int &click,int k,long long V[1001]){

for(int i=1;i<n;i++){

    if(V[i] == S + k){
        S = V[i];
        if(k==1){c1++;}
        else if(k==3){c3++;}
        click++;
        return 0;
    }
}

}


int check(int n, long long V[1001]){

int k = 1, click = 0;
int S = 0,C = 0;
int c1 = 0, c3 = 0;

while(click < n - 1){

C=S;
checkin(n,S,c1,c3,click,k,V);
if(S == C && k < 3) k++;
else k=1;
}
c3++;
cout<<c1*c3;

}


int main()
{

long long V[1001];
int inva = 0, n=1;

ifstream in("intrare.in");

while(in>>V[n]){
    n++;
}

check(n,V);

return 0;

}


