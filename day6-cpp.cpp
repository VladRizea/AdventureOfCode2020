#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int V[123];
char r[1000];

int main(){

    char x[100];
    int S=0,suma = 0,suma2 = 0, S2=0,rand=0;
    ifstream in("intrare.in");
    for(int i=97;i<=122;i++)
        V[i] = 0;

    while( in.getline(r,100))
    {
        if(strlen(r) != 0 )
        {
            for(int i=0;i<=strlen(r);i++){
                V[(int)r[i]] ++ ;
            }
            rand++;

        }
        else{
            suma = 0;
            suma2 = 0;
            for(int i=97;i<=122;i++){
                if(V[i]>=1) suma++;
            }
            for(int i=97;i<=122;i++){
                if(V[i]==rand) suma2++;
            }
            S= S+ suma;
            S2=S2+suma2;
            for(int i=97;i<=122;i++)
                V[i] = 0;
            rand = 0;

        }

        }

            suma = 0;
            suma2 = 0;
            for(int i=97;i<=122;i++){
                if(V[i]>=1) suma++;
            }
            for(int i=97;i<=122;i++){
                if(V[i]==rand) suma2++;
            }
            S= S+ suma;
            S2=S2+suma2;
            for(int i=97;i<=122;i++)
                V[i] = 0;
            rand = 0;

        cout<<"TEST 1 : "<<S<<endl;
        cout<<"TEST 2 : "<<S2<<endl;
    }
