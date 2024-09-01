#include<iostream>
#include<conio.h>
using namespace std;
class DivisorCalculator
{
	public:
		DivisorCalculator()
		{
			cout<<"Divisor Calculator is Created";
		}
		void calculateDivisor(int value)
		{
			for(int i=value; i>=1; i--)
			{
				if(value%i ==0)
				cout<<i<<"\n";
			}
		}
};
class UserInterface
{
	public:
		UserInterface()
		{
			cout<<"\nUserInterface is Created";
		}
		void takeInput(DivisorCalculator obj)
		{
			int value;
			rep:
			cout<<"Please Enter a Positive Integer: ";
			cin>>value;
			if(value>0)
			{
				obj.calculateDivisor(value);
			}
			else
			{
				cout<<"\n"<<value<<" is not a positive integer.\n";
				goto rep;
			}
		}
};
main()
{
	DivisorCalculator DC;
	UserInterface UI;
	char choice;
	cout<<"\n\nThis program is designed to exhibit the positive";
	cout<<"\ndivisors of positive integers supplied by you. The";
	cout<<"\nprogram will repeatedly prompt you to enter a";
	cout<<"\npositive integer. Each time you enter a positive";
	cout<<"\ninteger, the program will print all the divisors of";
	cout<<"\nyour integer in a column and in decreasing order\n\n";
	do{
		UI.takeInput(DC);
		rep:
		cout<<"would you like to see the divisors of another integer (Y/N)?";
		cin>>choice;
		if(choice!='Y' && choice!='y' && choice!='N' && choice!='n')
		{
			cout<<"\nPlease respond with Y (or y) for Yes and N (or n) for No\n";
			goto rep;
		}
		
	}
	while(choice=='Y' || choice=='y');
	getch();
	return 0;
}

