#include<iostream>
#include<string>

using namespace std;

class Student
{
	public:
		string name;
		Student() : name("") {}
		Student(string n) : name(n){}
};

class TreeNode
{
	public:
		Student* student;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : student(), left(NULL), right(NULL) {}
		TreeNode(Student* s) : student(s), left(NULL), right(NULL) {}
		TreeNode* insert(TreeNode* root, Student* student)
		{
			if(root == NULL)
			{
				return new TreeNode(student);
			}
			if(student->name < root->student->name)
			{
				root->left = insert(root->left, student);
			}
			else if(student->name > root->student->name)
			{
				root->right = insert(root->right, student);
			}
			return root;
		}
		TreeNode* remove(TreeNode* root, string name)
		{
			if(root == NULL)
			{
				return root;
			}
			if(name < root->student->name)
			{
				root->left = remove(root->left, name);
			}
			else if(name > root->student->name)
			{
				root->right = remove(root->right, name);
			}
			else
			{
				if(root->left == NULL)
				{
					TreeNode* temp = root->right;
					delete root;
					return temp;
				}
				else if(root->right == NULL)
				{
					TreeNode* temp = root->left;
					delete root;
					return temp;
				}
				TreeNode* temp = minValueNode(root->right);
				root->student = temp->student;
				root->right = remove(root->right, temp->student->name);
			}
			return root;
		}
		void inorder(TreeNode* root)
		{
			if(root != NULL)
			{
				inorder(root->left);
				cout<<root->student->name<<"\n";
				inorder(root->right);
			}
		}
		TreeNode* minValueNode(TreeNode* node)
		{
			TreeNode* current = node;
			while(current && current->left !=NULL)
			{
				current = current->left;
			}
			return current;
		}
};

main()
{
	TreeNode* root = NULL;
	TreeNode tree;
	int choice, numberOfStudent;
	string name;
	while(1)
	{
		cout<<"Menu: Examination Seat Allocation";
		cout<<"\n1. Allocate Seat";
		cout<<"\n2. Remove Student";
		cout<<"\n3. Display Seating According to Alphabetical Order";
		cout<<"\n4. Exit";
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the Number of Students for Alloacating Seats: ";
				cin>>numberOfStudent;
				cin.ignore();
				for(int i = 1; i<=numberOfStudent; i++)
				{
					cout<<"Enter Student Name: ";
					getline(cin,name);
					root = tree.insert(root, new Student(name));
				}
				break;
			case 2:
				cout<<"Enter Students Name to Remove: ";
				cin.ignore();
				getline(cin,name);
				root = tree.remove(root, name);
				break;
			case 3:
				cout<<"Seating Arrangement: \n";
				tree.inorder(root);
				break;
			case 4:
				exit(0);
		}
		
	}
}
