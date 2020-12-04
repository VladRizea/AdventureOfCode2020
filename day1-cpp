#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(){

    int V[1001],x,n=0,p1 = 1, p2 = 1;
    ifstream in("intrare.in");
    while(in>>x){
        V[n] = x;
        n++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           for(int k=0;k<n;k++){
            if(V[k] + V[j] == 2020) p1 = V[k]*V[j];
            if(V[i] + V[j] + V[k] == 2020) p2 = V[i] * V[j] * V[k];
           }
        }
    }

cout<<"TEST 1: "<<p1<<endl;
cout<<"TEST 2: "<<p2<<endl;
}
