#include<iostream>
#include<conio.h>
using namespace std;
class Task
{
	private:
		int taskID;
		string taskName, description, dueDate;
		Task *next;
	public:
		void setTaskID(int id)
		{
			taskID = id;
		}
		int getTaskID()
		{
			return taskID;
		}
		void setTaskName(string name)
		{
			taskName = name;
		}
		string getTaskName()
		{
			return taskName;
		}
		void setDescription(string desc)
		{
			description = desc;
		}
		string getDescription()
		{
			return description;
		}
		void setDueDate(string date)
		{
			dueDate = date;
		}
		string getDueDate()
		{
			return dueDate;
		}
		void setNext(Task *nextNode)
		{
			next = nextNode;
		}
		Task* getNext()
		{
			return next;
		}
};
class TaskStack
{
	private:
		Task *head;
	public:
		TaskStack()
		{
			head = NULL;
		}
		void pushTask(int taskID, string taskName, string taskDesc, string date)
		{
			Task *newNode = new Task;
			newNode -> setTaskID(taskID);
			newNode -> setTaskName(taskName);
			newNode -> setDescription(taskDesc);
			newNode -> setDueDate(date);
			newNode -> setNext(head);
			head = newNode;
		}
		void popTask()
		{
			Task *ptr = head;
			head = head -> getNext();
			delete ptr;
		}
		void topTask()
		{
			cout<<"Top Task - Name: "<<head -> getTaskName();
			cout<<", ID: "<<head -> getTaskID();
			cout<<", Description: "<<head -> getDescription();
			cout<<", Due Date: "<<head -> getDueDate()<<"\n";
		}
		void displayTasks()
		{
			Task *ptr = head;
			while(ptr !=NULL)
			{
			cout<<"Name: "<<ptr -> getTaskName();
			cout<<", ID: "<<ptr -> getTaskID();
			cout<<", Description: "<<ptr -> getDescription();
			cout<<", Due Date: "<<ptr -> getDueDate()<<"\n";
			}
		}
};
main()
{
	TaskStack TS;
	while(1)
	{
		int choice,id;
		string name, desc, date;
		cout<<"Task Management System";
		cout<<"\n1. Push a Task onto the Stack";
		cout<<"\n2. Pop a Task from the Stack";
		cout<<"\n3. Display the Top Task";
		cout<<"\n4. Display the Entire Stack";
		cout<<"\n5. Exit";
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter Task Name: ";
				cin>>name;	
				cout<<"Enter Task ID: ";
				cin>>id;
				cout<<"Enter Task Description: ";
				cin>>desc;
				cout<<"Enter Task Due Date: ";
				cin>>date;
				TS.pushTask(id, name, desc, date);
				break;
			case 2:
				TS.popTask();
				break;
			case 3:
				TS.topTask();
				break;
			case 4:
				cout<<"Task Stack:\n";
				TS.displayTasks();
				break;
			case 5:
				exit(0);
		}
	}
}
