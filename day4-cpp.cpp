#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char* A[8];char* OCHI[7];
int V[8];
char r[100];


void initialize(){
    A[1] = "byr";
    A[2] = "iyr";
    A[3] = "eyr";
    A[4] = "hgt";
    A[5] = "hcl";
    A[6] = "ecl";
    A[7] = "pid";
    A[8] = "cid";

    OCHI[1] = "amb";
    OCHI[2] = "blu";
    OCHI[3] = "brn";
    OCHI[4] = "gry";
    OCHI[5] = "grn";
    OCHI[6] = "hzl";
    OCHI[7] = "oth";
}

int get_an( int i){
    char an[100];
    strcpy(an , r + i + 5 );
    strcpy(an+4 , "" );
    int ani =0;
    for(int h=0;h<=3;h++){
        ani = ani *10 + (int)an[h] - 48;
    }
    return ani;
}

int validare_an(int an, int caz)
{

if(caz == 1){
    if(an < 1920 || an > 2002) return 0;
}
else if(caz == 2){
    if(an < 2010 || an > 2020) return 0;
}
else if(caz == 3){
    if(an < 2020 || an > 2030) return 0;
}
 return 1;

}

int gasire_caracter(char c,int i){
    for(int j=i+1;j<strlen(r);j++)
        if(r[j] == c) return j;
}

int validare_h(int i){
    int spa,pct,hei = 0;
    spa = gasire_caracter(' ',i);
    pct = gasire_caracter(':',i);
    if(r[spa - 2] == 'c' || r[spa - 2] == 'i'){
        for(int h=pct+1;h<=spa-3;h++){
           hei = hei *10 + (int)r[h] - 48;
        }
        if(r[spa - 2] == 'c'){
            if(hei >= 150 && hei <= 193) return 1;
        }
        if(r[spa - 2] == 'i'){
            if(hei >= 59 && hei <= 76  ) return 1;
        }
    }
    return 0;
}

int validare_hc(int i){
    int spa,pct,hei = 0;
    spa = gasire_caracter(' ',i);
    pct = gasire_caracter(':',i);
    if(r[pct + 1] == '#' && spa-pct-2 == 6){
        for(int h=pct+2;h<=spa-1;h++){
                if((int)r[h] < 48 || (int)r[h] > 57 &&  (int)r[h] < 97 || (int)r[h] > 102) return 0;
        }
        return 1;
    }
    return 0;
}

int validare_oci(int i){
        int spa,pct;
        spa = gasire_caracter(' ',i);
        pct = gasire_caracter(':',i);
        char x[100];
        strcpy(x , r + pct + 1 );
        strcpy(x+3 , "" );
        for(int j=1;j<=7;j++){
            if(strcmp(OCHI[j],x) == 0) return 1;
        }
        return 0;
}

int validare_id(int i){
        int spa,pct,sumax=0;
        spa = gasire_caracter(' ',i);
        pct = gasire_caracter(':',i);
        char x[100];
        strcpy(x , r + pct + 1 );
        strcpy(x+3 , "" );

        for(int j=pct+1;j<=spa-1;j++){
            sumax++;
            if((int)r[j] < 48 || (int)r[j] > 57) return 0;
        }
        if(sumax == 9)return 1;
        return 0;
}


void checking(char* x,int&suma,int&suma1,int k){
    for(int j=1;j<=7;j++){
       if(strcmp(A[j],x) == 0){
            suma1++;
            if(j==1 || j==2 || j==3) suma += validare_an(get_an(k),j);
            if(j==4) suma += validare_h(k);
            if(j==5) suma += validare_hc(k);
            if(j==6) suma += validare_oci(k);
            if(j==7) suma += validare_id(k);
        }
       }

    }




int main(){

    char x[100];
    int S=0,suma = 0, suma1=0, S1=0;
    ifstream in("intrare.in");
    for(int i=1;i<=7;i++)
        V[i] = 0;
    initialize();
    while( in.getline(r,100))
    {
        if(strlen(r) != 0 )
        {

            strcpy(x , r );
            strcpy(x+3 , "" );
            checking(x,suma,suma1,-1);

            for(int i=0;i<strlen(r);i++)
            if(r[i] == ' ')
            {
            strcpy(x , r + i + 1 );
            strcpy(x+3 , "" );
            checking(x,suma,suma1,i);
                    }

        }
        else
        {
            if(suma1 == 7) S1++;
            if(suma == 7)  S+=1;
            suma = 0;
            suma1 = 0;

            for(int i=1;i<=7;i++)
                V[i] = 0;

        }
    }
   cout<<"TEST 1: "<<S1<<endl;
   cout<<"TEST 2: "<<S;

}
