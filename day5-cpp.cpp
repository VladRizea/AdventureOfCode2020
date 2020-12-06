#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int rowu = 127, rowd = 0, colu = 7, cold = 0, A = 1, maxi = 0, M[128][9], m;
    char a,z,r[100];
    ifstream in("intrare.in");

    for(int i=0;i<=127;i++)
    for(int j=0;j<=7;j++)
        M[i][j] = 0;


    while(in>>r){
        A=0;
        rowu = 127;
        rowd = 0;
        colu = 7;
        cold = 0;
        for(int i=0;i<=5;i++){
            int S=0;
            S = rowu - rowd;
            S/=2;
            if(r[i]=='F') rowu=rowu - S - 1;
            if(r[i]=='B') rowd = rowd + S + 1;


            }

        for(int i=7;i<=8;i++){

            int S2=0;
            S2 = colu - cold;
            S2/=2;
            if(r[i]=='L') colu=colu - S2 - 1;
            if(r[i]=='R') cold = cold + S2 + 1;
        }


        if(r[6] == 'F') {A = rowd * 8;m=rowd;}
          else{ A = rowu * 8;m=rowu;}

        if(r[9] == 'L'){M[m][cold] = 1;A = A + cold;};
         if(r[9] == 'R') { M[m][colu] = 1; A = A + colu;};


        if(A > maxi) maxi = A;

}


cout<<"TEST 1 : "<<maxi<<endl;
    for(int i=7;i<=110;i++){
    for(int j=0;j<=7;j++)
        if(M[i][j] == 0) cout<<"Test 2 : "<<i*8+j;
}
}
