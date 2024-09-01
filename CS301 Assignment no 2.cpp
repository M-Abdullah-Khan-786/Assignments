#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Book
{
	public:
		string title, ISBN;
		Book(string t, string isbn) : title(t), ISBN(isbn) {}
};

class BSTNode
{
	public:
		Book book;
		BSTNode* left;
		BSTNode* right;
		BSTNode(Book b) : book(b), left(NULL), right(NULL) {}
};

class BookStack
{
	private:
		stack<Book> bookStack;
		BSTNode* root;
		BSTNode* insertBST(BSTNode* node, Book newBook)
		{
			if(node == NULL)
			{
				return new BSTNode(newBook);
			}
			if(newBook.title < node->book.title)
			{
				node->left=insertBST(node->left, newBook);
			}
			else if(newBook.title > node->book.title)
			{
				node->right=insertBST(node->right, newBook);
			}
			return node;
		}
		void inOrderTraversal(BSTNode* node)
		{
			if(node !=NULL)
			{
				inOrderTraversal(node->left);
				cout<<"Book: ";
				cout<<node->book.title<<"(ISBN: "<<node->book.ISBN<<")\n";
				inOrderTraversal(node->right);
			}
		}
		public:
			BookStack(): root(NULL) {}
			void push(Book newBook)
			{
				bookStack.push(newBook);
				root= insertBST(root, newBook);
			}
			void pop()
			{
				if(!bookStack.empty())
				{
					Book topBook = bookStack.top();
					bookStack.top();
					BSTNode* currentNode = root;
					BSTNode* parent = NULL;
					while(currentNode !=NULL && currentNode->book.title !=topBook.title)
					{
						parent = currentNode;
						if(topBook.title < currentNode->book.title)
						{
							currentNode=currentNode->left;
						}
						{
							currentNode=currentNode->right;
						}
					}
					if(currentNode !=NULL)
					{
						if(currentNode->left == NULL && currentNode->right == NULL)
						{
							if(parent == NULL)
							{
								root = NULL;
							}
							else if(parent->left == currentNode)
							{
								parent->left = NULL;
							}
							else
							{
								parent->right = NULL;
							}
							cout<<"Book Removed: "<<currentNode->book.title<<"\n\n";
							delete currentNode;
						}
						else if(currentNode->left == NULL)
						{
							if(parent == NULL)
							{
								root = currentNode->right;
							}
							else if(parent->left == currentNode)
							{
								parent->left = currentNode->right;
							}
							else
							{
								parent->right = currentNode->right;
							}
							cout<<"Book Removed: "<<currentNode->book.title<<"\n\n";
							delete currentNode;
						}
						else if(currentNode->right == NULL)
						{
							if(parent == NULL)
							{
								root = currentNode->left;
							}
							else if(parent->left == currentNode)
							{
								parent->left = currentNode->left;
							}
							else
							{
								parent->right = currentNode->left;
							}
							cout<<"Book Removed: "<<currentNode->book.title<<"\n\n";
							delete currentNode;
						}
						else
						{
							BSTNode* successor = currentNode->right;
							while(successor->left !=NULL)
							{
								successor = successor->left;
							}
							currentNode->book = successor->book;
							popSuccessor(currentNode, successor);
						}
					}
				}
			}
			void popSuccessor(BSTNode* parent, BSTNode* node)
			{
				if(node->left == NULL && node->right == NULL)
				{
					if(parent->left==node)
					{
						parent->left = NULL;
					}
					else
					{
						parent->right = NULL;
					}
					delete node;
				}
				else if(node->left ==NULL)
				{
					node->book = node->right->book;
					popSuccessor(node, node->right);
				}
				else
				{
					BSTNode* successor = node->left;
					while(successor->right !=NULL)
					{
						successor = successor->right;
					}
					node->book = successor->book;
					popSuccessor(node, successor);
				}
			}
			void listBooks()
			{
				if(root == NULL)
				{
					cout<<"Library is Empty\n";
				}
				else
				{
					cout<<"Library Book List: \n";
					inOrderTraversal(root);
				}
			}
			Book* search(string title)
			{
				BSTNode* currentNode = root;
				while(currentNode !=NULL)
				{
					if(title == currentNode->book.title)
					{
						return &currentNode->book;
					}
					else if(title < currentNode->book.title)
					{
						currentNode = currentNode->left;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
				return NULL;
			}
};
main()
{
	BookStack library;
	Book* foundBook;
	int choice;
	string Title,ISBN;
	library.push(Book("Aladdin", "BC123456789"));
	library.push(Book("Bad Habbits", "BC987654321"));
	while(1)
	{
		cout<<"Enter 1 List to All Books";
		cout<<"\nEnter 2 Add a New Books";
		cout<<"\nEnter 3 to Search for a Books";
		cout<<"\nEnter 4 to remove a New Books";
		cout<<"\nEnter 5 to Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				library.listBooks();
				cout<<"\n";
				break;
			case 2:
				cout<<"Enter Book Title: ";
				cin.ignore();
				getline(cin, Title);
				cout<<"\nEnter ISBN: ";
				getline(cin, ISBN);
				library.push(Book(Title, ISBN));
				cout<<"\n";
				break;
			case 3:
				cout<<"Enter Book Title: ";
				cin.ignore();
				getline(cin, Title);
				foundBook=library.search(Title);
				if (foundBook !=NULL)
				{
					cout<<"\nBook Found: \nBook: "<<foundBook->title;
					cout<<" (ISBN: "<<foundBook->ISBN<<")\n\n";
				}
				else
				{
					cout<<"Book Not Found.\n";
				}
				break;
			case 4:
				library.pop();
				break;
			case 5:
				exit(0);
		}
	}
}
