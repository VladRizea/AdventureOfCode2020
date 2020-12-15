#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

char x[1000], V[1001][1000],A[1001][1000];

int schimbari(char  V[1001][1000], char A[1001][1000] , int n,int m, int g){
    int S=0;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++)
            if(V[i][j] == A[i][j]) S++;
    }
    if(g == 1) return 0;
    return S;
}

void copiere(char  V[1001][1000], char A[1001][1000] , int n,int m){
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++)
            V[i][j] = A[i][j];
    }
}

void calculate(char  V[1001][1000], char A[1001][1000] , int n,int m){

    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++)
            A[i][j] = V[i][j];
    }

    int g = 1;
    while(schimbari(V,A,n,m, g) != m*n) {
    g = 0;
    copiere(V,A,n,m);
    int S=0;
    for(int i=0; i<n;i++){
        int S=0;
        for(int j=0;j<m;j++)
        {
            S=0;
            if(V[i+1][j] == '#') S++;
            if(V[i+1][j+1] == '#') S++;
            if(V[i+1][j-1] == '#') S++;
            if(V[i][j+1] == '#') S++;
            if(V[i][j-1] == '#') S++;
            if(V[i-1][j-1] == '#') S++;
            if(V[i-1][j] == '#') S++;
            if(V[i-1][j+1] == '#') S++;

            if(V[i][j] == 'L' && S==0) A[i][j] = '#';
            else if(V[i][j] == '#' && S>=4) A[i][j] = 'L';
            else A[i][j] = V[i][j];
            S=0;


        }
}

    }


int K=0;

        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++)
               if(A[i][j] == '#') K++;
        }


    cout<<"TEST 1: "<<K;

}



int main()
{



int inva = 0, n=0,m = 0;

ifstream in("intrare.in");

while(in.getline(x, 1000)){
    m=strlen(x);
    for(int i=0;i<strlen(x);i++){
        V[n][i] = x[i];
    }
    n++;
}
calculate(V,A,n,m);


}


