#include<iostream>
#include<conio.h>
using namespace std;
class list
{
	struct node
	{
		int data;
		node* next;
		node()
		{
			data=0;
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
			node* i=head;
			while(i->next!=NULL)
			{
				i=i->next;
			}
	    	i->next=new_node;
		}
		void delete_beg()
		{
			if(head==NULL)
			{
				cout<<"Link List is Empty"<<endl;
				return;
			}
			head=head->next;
			cout<<"Start Node Deleted"<<endl;
		}
		void delete_end()
		{
			if(head==NULL)
			{
				cout<<"Link List is Empty"<<endl;
				return;
			}
			node* i=head;
			while(i->next->next!=NULL)
			{
				i=i->next;
			}
	    	i->next=NULL;
	    	cout<<"End Node Deleted"<<endl;
		}
		void delete_specific(int x)
		{
			bool flag=false;
			node* i=head;
			if(head==NULL)
			{
				cout<<"Link List is Empty"<<endl;
				return;
			}
		
			while(i!=NULL)
			{
			    if(i->data==x)
				{
				   flag=true;
				   break;
				}
				i=i->next;
			}
			if(flag==true)
			{
			    i->next=i->next->next;
			}
			else
			{
			    cout<<"Element Not Found"<<endl;
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
			cout<<i->data<<" ";
		}
	    int length()
		{
			int len=0;
			node* i=head;
			while(i!=NULL)
			{
				len++;
				i=i->next;
			}
			return len;
		}
}l;
int main()
{
	int val;
	while(true)
	{
		system("cls");
		cout<<"--- Select ---"<<endl;
		cout<<"1. Insert at Beg"<<endl;
		cout<<"2. Insert at End"<<endl;
		cout<<"3. Delete Beg"<<endl;
		cout<<"4. Delete End"<<endl;
		cout<<"5. Delete Specific"<<endl;
		cout<<"6. Display"<<endl;
		cout<<"7. Length"<<endl;
		cout<<"0. Exit"<<endl;
		char choice;
		cout<<"Choice : ";
		cin>>choice;
		switch(choice)
		{
			case '0':
				return 0;
				break;
			case '1':
				system("cls");
				cout<<"Enter Value : ";
				cin>>val;
				l.insert_beg(val);
				cout<<val<<" Inserted into Start of List"<<endl;
				l.display();
				break;
			case '2':
				system("cls");
				cout<<"Enter Value : ";
				cin>>val;
				l.insert_end(val);
				cout<<val<<" Inserted into End of List"<<endl;
				l.display();
				break;
			case '3':
				system("cls");
				l.delete_beg();
				l.display();
				break;
			case '4':
				system("cls");
				l.delete_end();
				
				l.display();
				break;
			case '5':
				system("cls");
				cout<<"Enter Value : ";
				cin>>val;
				l.delete_specific(val);
				cout<<"Node Deleted"<<endl;
				l.display();
				break;
			case '6':
				system("cls");
				l.display();
				break;
			case '7':
				system("cls");
				cout<<"Length is : "<<l.length()<<endl;
				break;
			default:
				continue;
				break;
		}
		getch();
	}
}
