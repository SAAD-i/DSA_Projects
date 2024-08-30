#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node()
	{
		
		data=0;
		next=NULL;
	}
};
Node *head;
void ins_beg(int x)
{
	Node* new_node=new Node;
	new_node->data=x;
	new_node->next=NULL;
	//cout<<new_node->data<<endl;
	//cout<<new_node->next<<endl;
	if(head==NULL)
	{
		//cout<<"NULL"<<endl;
		head=new_node;
	}
	else
	{
		new_node->next=head;
		head=new_node; 
	}
}

void ins_end(int x)
{
	Node* new_node=new Node;
	new_node->data=x;
	new_node->next=NULL;
	Node* i=head;
	while(i->next!=NULL)
	{
		i=i->next;
	}
	i->next=new_node;
}
void ins_loc(int x)
{
	Node* new_node=new Node;
	new_node->data=x;
	new_node->next=NULL;
	Node* i=head;
	while(i->next!=NULL)
	{
		if(i->data>x && x>i->next->data)
		{
			new_node->next=i->next;
			i->next=new_node;
		}
		i=i->next;
	}
	if(i->data>x && x>i->next->data)
	{
		new_node->next=i->next;
		i->next=new_node;
	}
	
}
void del_beg()
{
	head=head->next;
}
void del_end()
{
	Node* i=head;
	while(i->next->next!=NULL)
	{
		i=i->next;
	}
	i->next=NULL;
	
}

void del_ele(int x)
{
	bool flag=false;
	Node* i=head;
	while(i->next!=NULL)
	{
		if(i->next->data==x)
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
void search(int x)
{
	Node* i=head;
	bool flag=false;
	int loc=1;
	while(i->next!=NULL)
	{
		loc++;
		if(i->next->data==x)
		{
			flag=true;
			break;
		}
		i=i->next;
	}
	if(flag==true)
	{
		cout<<"Element Found at Location "<<loc<<endl;
	}
	else
	{
		cout<<"Element Not Found"<<endl;
	}
}

void len()
{
	Node* i=head;
	int length=0;
	while(i->next!=NULL)
	{
		length++;
		i=i->next;
	}
	length++;
	cout<<"Length : "<<length<<endl;
}
void display()
{
	cout<<"Display"<<endl;
	Node* i=head;
	while(i->next!=NULL)
	{
		cout<<i->data<<endl;
		i=i->next;
		//cout<<i->data<<endl;
	}
	cout<<i->data<<endl;
}

int main()
{
	cout<<"LIST"<<endl;
	ins_beg(1);
	ins_beg(2);
	ins_beg(3);
	ins_beg(7);
	//ins_beg(5);
	//ins_beg(6);
	ins_loc(4);
//	del_beg();
//	del_end();
//	del_ele(5);
	//search(5);
	display();
	//len();
	cout<<"END"<<endl;
}
