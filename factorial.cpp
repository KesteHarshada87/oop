#include<iostream>
using namespace std;
int main()
{
	int n,i,f;
	cout<<"Enter number whose factorial you want to calculate..!";
	cin>>n;
	i=n;
	while(i>0)
	{
		f=n*(n-1);
		i--;
	}
	cout<<f;
}
