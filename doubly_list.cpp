#include<iostream>
using namespace std;
class doubly_list
{
	struct node
	{
		int data;
		node* prev;
		node* next;
		node()
		{
		   data=0;
		   prev=NULL;
		   next=NULL;
		}
	}*head;
	
	public:
		void insert_beg(int x)
		{
			node* new_node=new node;
			new_node->data=x;
			if(head==NULL)
			{
				head=new_node;
			}
			else
			{
				new_node->next=head;
				head->prev=new_node;
				head=new_node;
			}
		}
		void insert_end(int x)
		{
			node* new_node=new node;
			new_node->data=x;
			if(head==NULL)
			{
				head=new_node;
			}
			else
			{
				node* i=head;
				while(i->next!=NULL)
				{
					i=i->next;
				}
				new_node->prev=i;
				i->next=new_node;
			}
		}
		void display()
		{
			node* i=head;
			while(i->next!=NULL)
			{
				cout<<i->data<<" ";
				i=i->next;
			}
			cout<<i->data<<" "<<endl;
			while(i->prev!=NULL)
			{
				cout<<i->data<<" ";
				i=i->prev;
			}
			cout<<i->data<<" "<<endl;
		}
}list;
int main()
{
	list.insert_beg(1);
	list.insert_beg(2);
	list.insert_beg(3);
	list.display();
	list.insert_end(4);
	list.insert_end(5);
	list.display();
}
