//drzewa tire
#include<iostream>
#include<deque>
#include<string>
#include<vector>
using namespace std;
class Literka
{
public:
    Literka *przed;
    Literka* *nastepne=new Literka*[26];
    int potomki;
    string tresc;
    bool ost;

    Literka()
    {
        przed=NULL;
        ost=false;
        for(int i=0; i<26; i++)
        {
            nastepne[i]=NULL;
        }
        potomki=0;
    }

    ~Literka()
    {
        delete[]nastepne;
    }

};

class Tree
{
public:
    Literka* *Nowe=new Literka*[26];

    Tree()
    {
        for(int i=0; i<26; i++)
        {
            this->Nowe[i]=NULL;
        }
    }
    ~Tree()
    {
        delete[]Nowe;
    }

    void insertT(string slowo)
    {
        Literka *current = new Literka;
        current = this->Nowe[int(slowo[0])-96];
        int length=slowo.length();
        int start;
        if(current==NULL)
        {
            Literka *l = new Literka;
            l->tresc=slowo[0];
            this->Nowe[int(slowo[0])-96]=l;
            start=1;
            current = this->Nowe[int(slowo[0])-96];

        }
        else
        {
            current = this->Nowe[int(slowo[0])-96];
            int n=0;
            string porow1 ="";
            porow1+=slowo[n];
            string porow2 ="";
            porow2+=slowo[n+1];
            while(current->tresc == porow1)
            {
                for(int i=0; i<26; i++)
                {
                    if(current->nastepne[i]!=NULL && current->nastepne[i]->tresc==porow2)
                    {
                        current=current->nastepne[i];
                    }
                }
                n++;
                porow1 ="";
                porow1+=slowo[n];
                porow2 ="";
                porow2+=slowo[n+1];
            }
            start=n;
        }


        for(int j=start; j<length; j++)
        {
            Literka *li = new Literka;
            li->przed = current;
            li->tresc=slowo[j];
            current->nastepne[int(slowo[j])-96]=li;
            current->potomki++;
            current = li ;
        }
        current->ost=true;
    }



    float Preprint(Literka *K,vector<char> werb,float sum)
    {

werb.push_back('a');
if(K->potomki>0){

    for(int i=0;i<26;i++)
       {
           if(K->nastepne[i]!=NULL)
           {
            sum=Preprint(K->nastepne[i],werb,sum);

           }
       }
}
        if(K->ost==true )
        {
            K->ost=false;
            for(int i=0;i<werb.size();i++)
            {  sum++;
            }

        }

 return sum;

    }
     void suma(int N)
    {
         float sum=0.0;
        for(int i=0; i<26; i++)
        {
            if(this->Nowe[i]!=NULL)
            {
                vector<char> a;
                Literka *Li = new Literka;
                Li=this->Nowe[i];
                sum=Preprint(Li,a,sum);

            }
        }

        cout.precision(3);
        cout<<sum/N<<endl;
    }


};

void inorderT(Literka *Node)
{
    if(Node->potomki > 0)
    {
        for(int i=0; i<26; i++)
        {
            if(Node->nastepne[i]!=NULL)
            {
                inorderT(Node->nastepne[i]);

            }
        }
    }
    while(Node->przed!=NULL && Node->przed->potomki==1 && Node->przed->ost==false )
    {
        Node->przed->ost=Node->ost;
        Node->przed->potomki=Node->potomki;
        Node->przed->tresc=Node->przed->tresc + (Node->tresc);
        Node->przed->nastepne=Node->nastepne;

        if(Node->przed->potomki==0)
        {
            break;
        }

    }

}

void compress(Tree *Trie)
{
    for(int x=0; x<26; x++)
    {
        if(Trie->Nowe[x]==NULL)
        {
            continue;
        }
        else
        {
            inorderT(Trie->Nowe[x]);
        }
    }

}

int main()
{
    int N;

    while(cin>>N)
    {
         Tree Trie;
    string slowo;

//wpisywanie slow

        for(int i=0; i<N; i++)
        {
            cin>>slowo;
            Trie.insertT(slowo);

        }

        //kompresja
        compress(&Trie);

//suma wyliczanie i wypisywanie wyniku

        Trie.suma(N);

    }

    return 0;
}
