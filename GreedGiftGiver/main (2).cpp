/*
ID: china_i1
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include "stdio.h"
#include<map>

using namespace std;

struct GiveList
{
	vector<string> list;
	int amount;
	int receive;
};

int main()
{
	int NP = 0;
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);

	while(cin>>NP)
	{
		vector<string> names;
		string name;
		string receiver;
		int amount;
		int numofrcvrs;
		map<string, GiveList> groupgifts;
		GiveList gl;

		for(int i = 0; i < NP; ++i)
		{
			cin>>name;
			names.push_back(name);
		}

		for(int i = 0; i < NP; ++i)
		{
			gl.list.clear();
			gl.amount = 0;
			gl.receive = 0;
			cin>>name>>amount>>numofrcvrs;
			gl.amount = amount;

			if(numofrcvrs != 0)
			{
				gl.receive -= amount/numofrcvrs*numofrcvrs;
			}

			for(int j = 0; j < numofrcvrs; ++j)
			{
				cin>>receiver;
				gl.list.push_back(receiver);
			}

			groupgifts.insert(make_pair(name, gl));
		}

		for(map<string, GiveList>::iterator ii = groupgifts.begin();
			ii != groupgifts.end();
			++ii)
		{
			int size = ii->second.list.size();

			if(size != 0 && ii->second.amount != 0)
			{
				int everyone = ii->second.amount/size;
				ii->second.amount %= everyone;

				for(vector<string>::iterator jj = ii->second.list.begin();
					jj != ii->second.list.end();
					++jj)
				{
					groupgifts[*jj].receive += everyone;
				}
			}
		}

		for(vector<string>::iterator ii = names.begin();
			ii != names.end();
			++ii)
			cout<<*ii<<' '<<groupgifts[*ii].receive<<endl;

	}

	return 0;
}
