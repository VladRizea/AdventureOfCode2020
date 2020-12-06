#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(){
    int n = 1,x = 3,y = 5, z = 7,f=1, xmax=0,suma1 = 0,suma2 = 0,suma3 = 0,suma4 = 0,suma5 = 0,linenr = 1;
    char r[100];
    char* V[1000];
    ifstream in("intrare.in");
    in>>r;
    xmax=strlen(r);
    while(in>>r){
        if(r[n] == '#') suma1++;
        if(r[x] == '#') suma2++;
        if(r[y] == '#') suma3++;
        if(r[z] == '#') suma4++;
        x+=3;
        y+=5;
        z+=7;
        n++;
        if(linenr % 2 == 0 ) {
            if(r[f] == '#') suma5++;
            f++;
            if(f >= xmax) f -= xmax;
            }
        linenr++;
        if(x >= xmax) x -= xmax;
        if(y >= xmax) y -= xmax;
        if(z >= xmax) z -= xmax;
        if(n >= xmax) n -= xmax;


        }
long long prod = suma1*suma2*suma3*suma4;
cout<<"TEST 1: "<<suma2<<endl<<"TEST 2: "<<prod*suma5;


}
