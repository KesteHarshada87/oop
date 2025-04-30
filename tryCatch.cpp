#include<iostream>
#include<string>
using namespace std;
class BankAccount{
	private:
		string ownername;
	    double balance;
		
	public:
		BankAccount(string name,double bal){
			ownername=name;
			balance=bal;
		}
		void display(){
			cout<<"Ownername is:"<<ownername<<endl;
			cout<<"Initial balance is:"<<balance<<endl;
		}
		void deposite(){
			double amount;
			cout<<"Enter depositing money:"<<endl;
			cin>>amount;
			if(amount<=0){
				cout<<"Can't deposit money!!";
			}
			else{
		        balance=balance+amount;
				cout<<"New balance in "<<balance<<" Harshada Keste's account"<<endl;
			}
		}
		void withdraw(){
			double amount;
			cout<<"Enter amount you want to withdraw:"<<endl;
			cin>>amount;
			if(amount>balance){
				cout<<"Can't withdraw!!";
			}
			else{
				balance=balance-amount;
				cout<<"Account balance is:"<<balance;
			}
		}
		void transfer(BankAccount &to,double amount){
			
		}
};

int main(){
	BankAccount b1("Harshada",1000);
	BankAccount b2("Sandhya",4000);
	
	b2.display();
	b1.display();
	b1.deposite();
	b1.withdraw();
	b1.transfer(b1,8000);
	
}
