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
    deque<Literka*> next;
    int potomki;
    string tresc;
    bool ost;


    Literka()
    {
        przed=NULL;
        ost=false;
        potomki=0;
    }



};

class Tree
{
public:
    Literka* *Nowe=new Literka*[27];
    vector<int> Poz;
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
        current = this->Nowe[int(slowo[0])-97];
        this->Poz.push_back(int(slowo[0])-97);
        int length=slowo.length();
        int start;
        if(current==NULL)
        {
            Literka *l = new Literka;
            l->tresc=slowo[0];
            this->Nowe[int(slowo[0])-97]=l;
            start=1;
            current = this->Nowe[int(slowo[0])-97];

        }
        else
        {
            current = this->Nowe[int(slowo[0])-97];
            int n=0;
            string porow1 ="";
            porow1+=slowo[n];
            string porow2 ="";
            porow2+=slowo[n+1];
            while(current->tresc == porow1)
            {for(int i=0;i<current->next.size();i++){
if(!current->next.empty() && current->next[i]->tresc==porow2)
                    {
                        current=current->next.front();
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
            current->next.push_back(li);
            current->potomki++;
            current = li ;
        }
        current->ost=true;
    }



    float Preprint(Literka *K,vector<char> werb,float sum)
    {

werb.push_back('a');
if(K->potomki>0){

    for(int i=0;i<K->next.size();i++)
       {

            sum=Preprint(K->next[i],werb,sum);


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
        for(int i=0; i<this->Poz.size(); i++)
        {
               vector<char> a;
                Literka *Li = new Literka;
                Li=this->Nowe[this->Poz[i]];
                sum=Preprint(Li,a,sum);


        }

        cout.precision(3);
        cout<<sum/N<<endl;
    }


};

void inorderT(Literka *Node)
{
    if(Node->potomki > 0)
    {
            for(int i=0;i<Node->next.size();i++){
                inorderT(Node->next[i]);}



    }
    while(Node->przed!=NULL && Node->przed->potomki==1 && Node->przed->ost==false )
    {
        Node->przed->ost=Node->ost;
        Node->przed->potomki=Node->potomki;
        Node->przed->tresc=Node->przed->tresc + (Node->tresc);
        Node->przed->next=Node->next;

        if(Node->przed->potomki==0)
        {
            break;
        }

    }

}

void compress(Tree *Trie)
{
    for(int x=0; x<Trie->Poz.size(); x++)
    {

            inorderT(Trie->Nowe[Trie->Poz[x]]);

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
