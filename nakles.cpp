#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin("beads1.in");
	ofstream fout("beads.out");
	char carr[351]={"rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr"},last='a';
	int len,total=0,b=0,r=0,i=0,max=0,temp=len,stop=0,index=0;
	fin>>len;
	fin>>carr;
	//len=77;
	for(int j=0;j<len;j++)
	{
		total=0;
		b=1;r=1;	
		//for(i=j;i<len;i++)
		i=j;
		//cout<<(i=j)<<"\n";
		temp=len;
		while(temp--)
		{
		//	cout<<"i="<<i<<"\tr="<<r<<"\tb="<<b<<"\n";
			if(i==len)i=0;		
			if((carr[i]=='r')&&r)
			{
				last='r';
				//cout<<carr[i];
				total++;
				index=i+1;
				if(i==len-1)index=0;
				if(carr[index]=='b')
				{
					r=0;
				}
			}
			if((carr[i]=='b')&&b)
			{
				last='b';
				//cout<<carr[i];
				total++;
				index=i+1;
				if(i==len-1)index=0;
				if(carr[index]=='r')
				{
					b=0;
				}
			}
			if(b==1||r==1)
			{
				if(carr[i]=='w')
				{
				//cout<<"w";
				total++;
				index=i+1;
				if(i==len-1)index=0;
				if(carr[index]=='r')
				{
					if(r==0)
					break;
					else
					{
						if(last=='b')
						{
							b=0;
						}
					}
				}
				index=i+1;
				if(i==len-1)index=0;
				if(carr[index]=='b')
				{
					if(b==0)
					break;
					else
					{
						if(last=='r'){r=0;
						}
					}
				}
				
				/*if(carr[i+1]=='b'&&b==0)
				{
					break;
				}*/
				}
			}
			else
			{
				break;
			}
			i++;
		}
		//cout<<total<<"\n";
		if(total>max)
		{
			max=total;
		}
	}
	cout<<max<<"\n";
	return 0;
}
