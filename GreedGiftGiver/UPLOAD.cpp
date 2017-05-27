/*
ID: f2011501
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int GetID(string & name, string * ns, int NP)
{
    for(int i=0;i<NP;++i)
    {
        if(name == ns[i])return i;
    }
}

int main()
{
    /**/
    ifstream fin("gift1.in");
    streambuf * backup = cin.rdbuf();   // back up fin's streambuf
    cin.rdbuf(fin.rdbuf()); // assign file's streambuf to fin

    //ifstream fin("gift1.in");
    int NP;
    fin>>NP;
    string * names = new string[NP];
    int * money = new int[NP];
    ofstream fout("gift1.out");

    for(int i=0;i<NP;++i)
    {
        fin>>names[i];
        money[i] = 0;
    }
    //start to process money
    for(int i=0;i<NP;++i)
    {
        string curr_name, temp;
        int money_give_out;
        int n_out;
        fin>>curr_name;
        fin>>money_give_out;
        fin>>n_out;
        money[GetID(curr_name,names,NP)] -= money_give_out;
        for(int j=0;j<n_out;++j)
        {
            fin>>temp;
            money[GetID(temp,names,NP)] += money_give_out / n_out;
        }
        if(n_out > 0)money[GetID(curr_name,names,NP)] += money_give_out % n_out;
        else if(n_out == 0)money[GetID(curr_name,names,NP)] += money_give_out;
    }


    for(int i=0;i<NP;++i)
    {
        fout<<names[i]<<" "<<money[i]<<endl;
    }
    fin.close();
    fout.close();

    return 0;
}
