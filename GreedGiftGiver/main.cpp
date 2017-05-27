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
    ifstream fin("E:\\Projects\\FILEIN");
    streambuf * backup = cin.rdbuf();   // back up cin's streambuf
    cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin

    int NP;
    cin>>NP;
    //string * names = new string[NP];
    //int * money = new int[NP];
    string names [10];
    int money[10];

    for(int i=0;i<NP;++i)
    {
        cin>>names[i];
        money[i] = 0;
    }
    //start to process money
    for(int i=0;i<NP;++i)
    {
        string curr_name, temp;
        int money_give_out;
        int n_out;
        cin>>curr_name;
        cin>>money_give_out;
        cin>>n_out;
        money[GetID(curr_name,names,NP)] -= money_give_out;
        for(int j=0;j<n_out;++j)
        {
            cin>>temp;
            money[GetID(temp,names,NP)] += money_give_out / n_out;
        }
        if(n_out > 0)money[GetID(curr_name,names,NP)] += money_give_out % n_out;
        else if(n_out == 0)money[GetID(curr_name,names,NP)] += money_give_out;
    }

    int sum = 0;
    for(int i=0;i<NP-1;++i)
    {
        cout<<names[i]<<" "<<money[i]<<endl;sum+=money[i];
    }cout<<names[NP-1]<<" "<<money[NP-1];sum+=money[NP-1];
    cout<<endl<<"sum : "<<sum<<"\n";
    cin.rdbuf(backup);     // restore cin's original streambuf
    return 0;
}
