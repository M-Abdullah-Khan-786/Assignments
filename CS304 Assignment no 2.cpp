#include<iostream>
#include<string>
#include<iomanip>

class Base
{
public:
	virtual void display() const=0;
};
class Child1: public Base
{
	private:
		std::string studentName;
	public:
		Child1(const std::string& name) : studentName(name){}
		
		void display() const override{
		std::cout<<"------------------"<<std::endl;
		std::cout<<"My name is: "<<studentName<<std::endl;
		}
};

class Child2: public Base
{
	private:
		std::string course;
	public:
		Child2(const std::string& courseName) : course(courseName){}
		
		void display() const override{
		std::cout<<"________________________________"<<std::endl;
		std::cout<<"I am enrolled in course: "<<course<<std::endl;
		}
};

void showID(int* array, size_t size)
{
	std::cout<<"------------------"<<std::endl;
		std::cout<<"My VUID is: ";
		for (size_t i=0; i<size; ++i){
			std::cout<<array[i];
			if(i<size-1){
				std::cout<<",";
			}
		}
		std::cout<<std::endl;
		std::cout<<"------------------"<<std::endl;
		std::cout<<std::endl;
}

void sumLastThreeDigits(int* array, size_t size)
{
	if(size<3){
		std::cout<<"Cannot calculate the sum of the last three digits."<<std::endl;
		return;
	}
	int sum=0;
	for(size_t i=size-3; i<size; ++i){
		sum +=array[i];
	}
	std::cout<<"Sum of the last three digits of my Vu Id is: "<<sum<<std::endl;
}

int main()
{
	int studentID[]={1,2,3,4,5,6,7,8};
	
	std::string S1 ="Muhammad Abdullah Khan";
	std::string S2 ="CS304P";
	
	Child1 d1(S1);
	Child2 d2(S2);
	
	Base* p =NULL;
	
	p=&d1;
	p->display();
	
	p=&d2;
	p->display();
	
	showID(studentID, sizeof(studentID) / sizeof(studentID[0]));
	
	sumLastThreeDigits(studentID, sizeof(studentID) / sizeof(studentID[0]));
	
	return 0;
}
