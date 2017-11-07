#include<iostream>
#include<string>
#include<vector>
//sortowanie u³amków do end of file
using namespace std;
// nwd
    int nwd(int a,int b)
    {  if(a>b)swap(a,b);
        int r;
        while(b!=0)
        {   r=a%b;
            a=b;
            b=r;
        }
        return a;}
//nww
int nww(int a,int b){
    int w=(a*b)/nwd(a,b);
    return w;}

class Ulamek {
public:
    int l; //przechowuje znak
    int  m;
Ulamek(){
l=0;
m=1;
}
Ulamek ustaw(int a,int b){
    if(b!=0){
        l=a;
        m=b;}
    else cout<<"INVALID"<<endl;
}

Ulamek (int l, int m){
if(this -> m==0){cout<<"INVALID"<<endl;}
this->l=l;
this->m=m;
}

 void ustawl(int a)
    {  l=a;
        m=1;}
void ustawm(int b)
    {m=b;}
friend void wyswietl( Ulamek u)
{
    if(u.m!=1)cout<<u.l<<"|"<<u.m<<" ";
    else cout<<u.l<<" ";
}
int vm(){ return this->m;}
int vl(){return this->l;}
//skraca
 void skr()
    {   int nw=nwd(this->l,this->m);
        if(nw>1)
        {this->m=m/nw;
        this->l=l/nw;}
    }
bool operator<(Ulamek u1)
{
    if(this->l>=0 && u1.l<0)return false;
    else if(this->l<0 && u1.l>=0)return true;
    else if(this->m != u1.m){ int wsm=nww(this->m,u1.m);


            this -> l = (this ->l)*(wsm/this ->m );
            this -> m = wsm;
            u1.l = (u1.l)*(wsm/u1.m);
            u1.m  = wsm;
    }

        if(this->l<u1.l  &&  this->l>0)
            {  u1.skr();this->skr();return true;}
        else if(this->l>0)
             {  u1.skr();this->skr();return false;}
        if(this->l<u1.l  &&  this->l<0)
            {  u1.skr();this->skr();return true;}
        else { u1.skr();this->skr();return false;}
        }

};


void wstaw(vector<Ulamek>&T,Ulamek W)
{

    int i=0;
    while(i<T.size() && T[i]<W ){i++; }
          if(i==T.size()) {

            T.push_back(W);
    }

    else {

            Ulamek z=T[i],q;
            T[i]=W;
            i++;
            while(i!=T.size()){q=T[i];T[i]=z;i++;z=q; }
            T.push_back(z);
            }

}

int main(){
vector<Ulamek>T;
string a="";
string c="";
Ulamek W;
while(cin>>c){a=a+c+' ';}

if(a.size()==1)
    {     Ulamek P(int(a[0]),1);
         T.push_back(P);}
else{
    int r=0;

while(r<a.size()-1){
bool minu= false;
     W.ustaw(0,1);
     if(a[r]=='-'){minu = true;r++;}

        while((int)a[r]>47 && (int)a[r]<58)
                    {  W.ustawl((W.vl())*10+(int)a[r]-48);
                        r++;
                    }
        if(minu){W.ustawl(W.vl()*(-1));minu=false;}
        if(a[r]=='|'){
                    r++;
                W.ustawm(0);
                while((int)a[r]>47 && (int)a[r]<58)
                    {
                           W.ustawm((W.vm())*10+(int)a[r]-48);
                        r++;
                    }
                    }
        if(a[r]==' ') {W.skr();  r++;        }
            if(T.size()==0){

                   T.push_back(W);}
            else { wstaw(T,W);}


}


}

for(int c=0;c<T.size();c++){
        wyswietl(T[c]);
        }

        cout<<endl;

return 0;}
