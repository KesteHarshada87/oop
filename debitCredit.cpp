#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cout<<"How many transactions you want?";
	cin>>a;
	int total[20];
	int total1[20];
	total[0]=1;
		total1[0]=0;
	cout<<"How many rupees you want to deposit?";
		cin>>b;
	for(int i=0;i<a;i++)
	{
		
		cout<<"Click 1 if you want to deposit else click 0.";
		cin>>c;
		
		if(c==1){
			
			
			cout<<"How many rupees you want to deposit?";
			cin>>e;
		total[i]=total[i]+b;
		total1[i]=total[i];
		cout<<"\n"<<total[i];
	       
	    }
	    
	    if(c==0)
	    {
	    	cout<<"How many rupees you want to withdraw?";
	    	cin>>d;
	    	total1[i]=total1[i]-d;
	    	cout<<"\n"<<total1[i];
		}
	}
	cout<<total;
}
