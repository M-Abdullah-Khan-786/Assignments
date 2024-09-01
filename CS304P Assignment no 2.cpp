#include<iostream>
#include<string>

class BankAccount{
	protected:
			int accountNumber;
			std::string accountHolderName;
			double balance;
	
	public:
		BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0){}
		
		BankAccount(int accNumber, const std::string &accHolderName, double bal)
			: accountNumber(accNumber), accountHolderName(accHolderName), balance(bal){}
			
		virtual void displayAccountInfo(){
			std::cout<<"Account Number: "<<accountNumber<<"\n";
			std::cout<<"Account Name: "<<accountHolderName<<"\n";
			std::cout<<"Balance: RS "<<balance<<"\n";
		}
};

class SavingsAccount: public BankAccount
{
	private:
		double interestRate;
	public:
		SavingsAccount() : interestRate(0.0){}
		
		SavingsAccount(int accNumber, const std::string &accHolderName, double bal, double rate)
		 : BankAccount(accNumber, accHolderName, bal), interestRate(rate){}
		
		void displayAccountInfo() override{
		BankAccount::displayAccountInfo();
		std::cout<<"Interset Rate: "<<interestRate<<"%"<<std::endl;
		}
};

class CreditCardAccount: public BankAccount
{
	private:
		double creditLimit;
	public:
		CreditCardAccount() : creditLimit(0){}
		
		CreditCardAccount(int accNumber, const std::string &accHolderName,double bal, double limit)
		 : BankAccount(accNumber, accHolderName, bal), creditLimit(limit){}
		
		void displayAccountInfo() override{
		BankAccount::displayAccountInfo();
		std::cout<<"Credit Limit: RS"<<creditLimit<<std::endl;
		}
};


int main()
{
	SavingsAccount abdullahSavingsAccount(12345678, "Muhammad Abdullah Khan",15000, 2.5);
	std::cout<<"Savings Account Information: "<<std::endl;
	abdullahSavingsAccount.displayAccountInfo();
	std::cout<<std::endl;
	
	CreditCardAccount abdullahCreditCardAccount(12345678, "Muhammad Abdullah Khan",1200, 1000);
	std::cout<<"Credit Card Account Information: "<<std::endl;
	abdullahCreditCardAccount.displayAccountInfo();
	return 0;
}
