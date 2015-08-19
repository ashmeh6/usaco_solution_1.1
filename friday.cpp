/*
ID: ashishm3
PROG: friday
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
	ifstream fin ("friday.in");
	ofstream fout("friday.out");
	int arr[7]={0,0,0,0,0,0,0},day=0,notleap=1,syear=1900,n,last;
	fin>>n;
	last=n+1900;
	char days[7][7]={"sun","mon","tue","wed","thu","fri","sat"};
	for(syear=1900;syear<last;syear++)
	{
		if(syear%4==0)
		{
			notleap = 0;
		}
		else
		{
			notleap = 1;
		}
		if(syear==1900||syear==2100||syear==2200||syear==2300||syear==2400)
		{
			notleap = 1;
		}
	for(int i=1;i<=12;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		{
			arr[day]++;
			day+=3;
			day%=7;
			
		}
		if(i==4||i==6||i==9||i==11)
		{
			arr[day]++;
			day+=2;
			day%=7;
			
		}
		if(i==2)
		{
			if(notleap)
			{
				arr[day]++;
			}
			else		// for leap year
			{
				arr[day]++;
				day+=1;
				day%=7;	
			}
		}
	}
}
	for(int i=0;i<7;i++)
	{
		fout<<arr[i];
		if(i==6)
		{
			fout<<"\n";
		}
		else
		{
			fout<<" ";
		}
	}
	return 0;
}
