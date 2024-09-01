#include<iostream>
using namespace std;
unsigned int stringToInt(string s){
	int len = s.length();
	unsigned int res = 0;
	for(int i=0; i<len; ++i){
		res = res*10;
		res = res + s[i] - '0';
	}
	return res;
}
int main(){
	
	string barCode = "1234567";
	unsigned int ans = stringToInt(barCode);
	unsigned int div = ans/2;
	unsigned int mul = ans*2;
	cout<<"Original Barcode:"<<barCode<<endl;
	cout<<"Numeric Part:"<<ans<<endl;
	cout<<"Bitwise AND result:"<<(div & mul)<<endl;
	cout<<"Right shift result:"<<(ans>>1)<<endl;
	cout<<"Left shift result:"<<(ans<<1)<<endl;
	return 0;
}
