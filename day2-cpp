#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int aflare(int mini, int maxi, char x, char* c){
    int suma = 0;
    char t[100];
    strcpy(t,c);

    for (int i = 0; i < strlen(c); i++){
        if (c[i] == x)
                suma++;
}
    if(suma < mini) return 0;
    if(suma > maxi) return 0;
    if(suma >= mini && suma <=maxi) return 1;
}

int aflare2(int mini, int maxi, char x, char* c){
        int s=0;
        if(c[mini] == x) s++;
        if(c[maxi] == x) s++;
        if(s==1) return 1;
        return 0;

}
int main()
{
    int V[1001],n=1,x,y,s1=0,s2=0;
    char a,z,r[100];
    ifstream in("intrare.in");

    while(in>>x>>z>>y>>a>>z){
        in.get(r,100);
        s1+=aflare(x,y,a,r);
        s2+=aflare2(x,y,a,r);

    }

    cout<<"TEST 1: "<<s1<<endl;
    cout<<"TEST 2: "<<s2<<endl;

}
