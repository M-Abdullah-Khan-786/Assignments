#include<iostream>
#include<conio.h>
using namespace std;
class Islamic_info
{
	public:
		void Quran_info()
		{
			cout<<"Quran Details";
			cout<<"\nTotal Parrah: 30";
			cout<<"\nSurrah: 114";
			cout<<"\nMadani Surrah: 28";
			cout<<"\nMakki Surrah: 86";
			cout<<"\nTotal Ayyat: 6666\n";
		}
		void display_list(int a[5])
		{
			cout<<"Faraz Rakat in Each Prayer are: ";
			for(int i=0; i<=4; i++)
			cout<<a[i]<<" ";
			cout<<"\n";
		}
		void sum_five_prayer_faraz_rakat(int a[5])
		{
			int sum = 0;
			for(int i=0; i<=4; i++)
			sum += a[i];
			cout<<"Total Faraz Rakat in Five Prayers: "<<sum<<"\n";
		}
		void showChoices()
		{
			cout<<"MENU";
			cout<<"\n1: Quran Info";
			cout<<"\n2: Display List of Five Prayers Faraz Rakat";
			cout<<"\n3: Sum All Five Prayers Faraz Rakat";
			cout<<"\n4: Exit";
			cout<<"\nEnter Your Choice: ";
		}
};
main()
{
	int faraz_rakat[5] = {2,4,4,3,4},choice;
	Islamic_info obj;
	while(1)
	{
		obj.showChoices();
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.Quran_info();
				break;
			case 2:
				obj.display_list(faraz_rakat);
				break;
			case 3:
				obj.sum_five_prayer_faraz_rakat(faraz_rakat);
				break;
			case 4:
				exit(0);
		}
	}
}
