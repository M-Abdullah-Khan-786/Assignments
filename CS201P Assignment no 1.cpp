#include <iostream>
#include <cmath>

double calculateGross(double grossSales){
	double commission=0.09*grossSales;
	double earnings=700+commission;
	return earnings;
}
int main(){
	double totalEarnings=0.0;
	double Sales1=5000;
	double earnings1=calculateGross(Sales1);
	totalEarnings+=earnings1;
	std::cout<<"Sales Person 1 Gross Earnings:"<<earnings1<<"PKR\n";
	
	double Sales2=7000;
	double earnings2=calculateGross(Sales2);
	totalEarnings+=earnings2;
	std::cout<<"Sales Person 2 Gross Earnings:"<<earnings2<<"PKR\n";
	
	double Sales3=9000;
	double earnings3=calculateGross(Sales3);
	totalEarnings+=earnings3;
	std::cout<<"Sales Person 3 Gross Earnings:"<<earnings3<<"PKR\n";
	
	std::cout<<"Total Gross Sale Earnings for Week:"<<totalEarnings<<"PKR\n";
	
	return 0;
	}

