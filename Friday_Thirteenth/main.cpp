/*
ID: f2011501
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

bool isLeap(int year)
{
    if( (year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0) ) return true;
    else return false;
}

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int N;
    fin>>N;
    int month_day[12] = {31,31,28,31,30,31,30,31,31,30,31,30};
    int day_count = 13;
    int week[7] = {0};
    for(int year = 1900; year<1900+N; ++year)
    {
        for(int month = 0; month < 12; ++month)
        {
            if(month == 2 && isLeap((year)))day_count += 29;
            else if(month == 2 && !isLeap((year)))day_count += 28;
            else if(year == 1900 && month == 0)day_count += 0;
            else day_count += month_day[month];
            if(day_count % 7 == 0)week[6]++;
            else week[ day_count % 7 - 1] ++;
        }
    }

    fout<<week[5]<<" "<<week[6]<<" ";
    for(int i = 0; i<4; ++i)fout<<week[i]<<" ";fout<<week[4];
    fout<<endl;
    fout.close();
    return 0;
}
