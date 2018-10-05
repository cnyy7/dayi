#include <iostream>
#include <cstdlib>
using namespace std;

//表示银行账户的类，名额账户具有余额和拥有者，并且按月获取利息，所有账户利率相同

class Account{
public:
	Account(string, double);
	void applyint();    // 余额加利息
	static double getRate();  
	static void setRate(double); 
	double getAmount();
private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

Account::Account(string name, double amount){
	owner = name;
	this->amount = amount;
}

void Account::applyint(){ amount += amount * interestRate; }

double Account::getRate(){ return interestRate; }

void  Account::setRate(double newRate){ interestRate = newRate; }

double Account::interestRate = initRate();

double Account::getAmount(){ return amount; }

double Account::initRate(){
	double initR;
	cin >> initR;
	return initR;
}

int main()
{
	Account a1("Mary", 100);
	a1.applyint();
	cout<<a1.getAmount()<<endl;

	Account::setRate(0.6);
	a1.applyint();
	cout << a1.getAmount() << endl;

	cout << Account::getRate() << endl;

	system("pause");
	return 0;

}
