#include <iostream>
#include <cmath>

using namespace std;

double fallingdistance(double t){
	const double g = 9.8;
	double d = 0.5*g * pow (t,2);
	return d;
}

int main(){
	const int NUM_Times = 5;
	double times[NUM_Times] = {1, 3, 5, 7, 9};
	double sum = 0;
	for (int i=0; i < NUM_Times; i++){
		double distance = fallingdistance (times[i]);
		sum += distance;
		cout << "Times" << times[i] << "seconds:" << distance << "meters"  <<endl;
	}
	double average = sum / NUM_Times;
	cout << "Average distance Coverd:" << average << "meters" <<endl;
	return 0;
}

