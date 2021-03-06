Task #.2: Estimated Time: 30 Mins.
Write C++ program to delete each alternate node of a singly linked list.
For Example: 1->2->3->4->5->6->7->8->NULL
should be restructured to
1->3->5->7->NULL
Coded by Farhan Ashraf
#include<iostream>
using namespace std;
class List {public:
	int data;
	List* next;
};
				  int n;//number of linklists
List* head = NULL;
List* tail = NULL;
void display(int n);
void insert(int n);
void altdestroy(int& n);
void main() {
	
	cout << "Enter the number of link list you want to create: "; cin >> n;
	for (int i = 0; i < n; i++)
		insert(i);

	display(n);
	cout << "After destroying the alternative nodes the link list is as follow: " << endl;
	altdestroy(n);
	display(n);
}

void display(int n) {
	List* temp = new List;
	temp = head;
	for (int i = 1; i <= n; i++)
	{
		if (temp != NULL)
		{
			cout << "The value of List " << i << " is: " << temp->data << endl;
			temp = temp->next;
		}
		else {
			system("pause"); return;
		}

	}
	temp = NULL;
	delete temp;

}

void insert(int a) {

	if (tail == NULL)
	{
		List* temp = new List;
		temp->data = a;
		temp->next = NULL;
		tail = temp;
		head = temp;

	}
	else if (tail != NULL) {
		List* temp = new List;
		tail->next = temp;
		tail = temp;
		tail->data = a;
		tail->next = NULL;

	}


}
void altdestroy(int& n) {
	int count = 0;
	List* temp = new List;
	List* tempr = new List;
	temp = head;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0) {
			if (temp->next != NULL) {
				tempr->next = temp->next;
			}
			else tempr->next = NULL;
			count++;
			List* tempdelete;
			tempdelete = temp;
			temp = tempr->next;
			delete tempdelete;

		}
		else
		{
			tempr = temp;
			if (i != n)
			{
				temp = tempr->next;
			}
			else return;
			
		
		}
	}
	n = n - count;
	delete tempr;
	delete temp;
}


