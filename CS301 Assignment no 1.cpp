#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;

class Node
{
	private:
		int object;
		Node *nextNode;
	public:
		void set(int value)
		{
			object = value;
		}
		int get()
		{
			return object;
		}
		void setNext(Node* ptr)
		{
			nextNode = ptr;
		}
		Node* getNext()
		{
			return nextNode;
		}
};
class List
{
	public:
		Node* headNode;
		Node* currentNode;
		Node* lastCurrentNode;
		List()
		{
			headNode = NULL;
			currentNode = NULL;
			lastCurrentNode = NULL;
		}
		void add(List obj)
		{
			if(headNode == NULL)
			{
				headNode = obj.currentNode;
				lastCurrentNode = obj.currentNode;
			}
			else
			{
				lastCurrentNode -> setNext(obj.currentNode);
				lastCurrentNode = obj.currentNode;
			}
		}
		void get(int size)
		{
			currentNode = headNode;
			for(int i=1; i<size; i++)
			{
				next();
			}
			cout<<"\nThe Middle Element is : "<<currentNode -> get();
		}
		void next()
		{
			currentNode = currentNode -> getNext();
		}
		friend void traverse();
		friend List addNodes(int);
		friend List findMiddle();
};
void traverse(List obj)
{
	obj.currentNode = obj.headNode;
	while(obj.currentNode != NULL)
	{
		cout<<"\tList Element  "<<obj.currentNode -> get()<<"\n";
		obj.next();
	}
};
List addNodes(int value)
{
	List obj;
	obj.currentNode = new Node;
	obj.currentNode -> set(value);
	obj.currentNode -> setNext(NULL);
	return obj;
}
List findMiddle(int size, List obj)
{
	obj.get((size/2)+1);
}
main()
{
	int size,id;
	List obj;
	srand(time(0));
	size = 3 + (rand()%7);
	cout<<"Randomly Generated Size of the Linked List is : "<<size<<"\n";
	for(int i=1; i<=size; i++)
	{
		cout<<"Enter Numeric Character of Your VU ID\n";
		cin>>id;
		obj.add((addNodes(id)));
	}
	cout<<"\n\n";
	traverse(obj);
	findMiddle(size, obj);
	getch();
	return 0;
}
