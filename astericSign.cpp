#include<iostream>
using namespace std;
int main(){
	int n=6;
	for(int i=0;i<n;i++) //for(i=0;<n;i++)
	{                       //for(j=0;j<i+1;j++) 
		for(int j=0;j<n;j++)  
		{
			if(i>=j)
			{
				cout<<"*";
			}
		}
		cout<<endl;
	}
}
