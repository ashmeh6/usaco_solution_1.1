/*
ID: ashishm3
PROG: gift1
LANG: C++                  
*/

#include<iostream>
#include <fstream>
#include<string.h>
using namespace std;
int main()
{
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	int n,index,give,part=1;
	fin>>n;
	int*money = new int[n];
	string s[n],givr,takr;
	
	for(int i=0;i<n;i++)
	{
		money[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		fin>>s[i];
	}
	x:
	while(fin>>givr)
	{
		
		for(int i=0;i<n;i++)
		{
			if(!givr.compare(s[i]))
			{
				index = i;
				break;
			}
		}
		fin>>give;
		fin>>part;
		money[index]-=give;
		if(part==0)
		{
			goto x;
			
			return 0;
		}
		money[index]+=(give%part);
		for(int i=0;i<part;i++)
		{
			fin>>takr;
			for(int j=0;j<n;j++)
			{
				if(!takr.compare(s[j]))
				{
					money[j]+=(give/part);
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		fout<<s[i]<<" "<<money[i]<<"\n";
	}
	return 0;

}