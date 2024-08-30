#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
class Ticket
{
	string phone_no;
	int fare;
	string time;
	int route_id;
	string route;
	string status;
	public:
		int id;
		string name;
		string type;
		string start_station;
		string end_station;
		Ticket()//Constructor
		{
			id=0;
			name="";
			phone_no="";
			type="";
			fare=0;
			start_station="";
			end_station="";
			time="";
			route="";
			status="Pending";
		}
		void input();
		void display();
		bool compare_id(int t_id)
		{
			if(id==t_id)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
}t;
struct Station
{
	int id;
	string name;
	string route1_time;
	string route2_time;
	Station()
	{
		id=0;
		name="";
	}
}s[4];
class list
{
	struct node
	{
		Ticket data;
		node* next;
		node()
		{
			next=NULL;
		}
	}* head;
	public:
		
		void insert_beg(Ticket x)
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
		void insert_end(Ticket x)
		{
			node* new_node=new node;
			new_node->data=x;
			node* i=head;
			if(head==NULL)
			{
				head=new_node;
			}
			else
			{
				while(i->next!=NULL)
				{
				    i=i->next;
				}
				i->next=new_node;
			}
		}
		void delete_beg()
		{
			head=head->next;
		}
		void delete_end()
		{
			node* i=head;
			while(i->next->next!=NULL)
			{
				i=i->next;
			}
	    	i->next=NULL;
		}
		void search()
		{
			if(head==NULL)
			{
				cout<<"\t\t\t.No Tickets to Search."<<endl;
				return;
			}
			node* i=head;
			cout<<"--- Select Search ---"<<endl;
			cout<<"1.By ID"<<endl;
			cout<<"2.By Name"<<endl;
			cout<<"3.By Class"<<endl;
			cout<<"\nChoice : ";
			int choice;
			cin>>choice;
			if(choice==1)
			{
				int id;
				cout<<"\nEnter ID : ";
				cin>>id;
				system("cls");
				cout<<"============================="<<endl;
				cout<<"|  Train Management System  |"<<endl;
				cout<<"============================="<<endl<<endl;
				while(i->next!=NULL)
				{
					if(i->data.id==id)
					{
						i->data.display();
					}
				    i=i->next;
				}
				if(i->data.id==id)
				{
					i->data.display();
				}
			}
			else if(choice==2)
			{
				string name;
				cout<<"Enter Name : ";
				cin.ignore();
				getline(cin,name);
				system("cls");
				cout<<"============================="<<endl;
				cout<<"|  Train Management System  |"<<endl;
				cout<<"============================="<<endl<<endl;
				while(i->next!=NULL)
				{
					if(i->data.name==name)
					{
						i->data.display();
					}
				    i=i->next;
				}
				if(i->data.name==name)
				{
					i->data.display();
				}
			}
			else if(choice==3)
			{
				int c;
				string cls;
				cout<<"--- Select Class ---"<<endl;
				cout<<"1.Economy"<<endl;
				cout<<"2.Buisness"<<endl;
				cout<<"\nChoice : ";
				cin>>c;
				if(c==1)
				{
					cls="Economy Class";
				}
				else if(c==2)
				{
					cls="Buisness Class";
				}
				else
				{
					cls="Economy Class";
				}
				system("cls");
				cout<<"============================="<<endl;
				cout<<"|  Train Management System  |"<<endl;
				cout<<"============================="<<endl<<endl;
				while(i->next!=NULL)
				{
					if(i->data.type==cls)
					{
						i->data.display();
					}
				    i=i->next;
				}
				if(i->data.type==cls)
				{
					i->data.display();
				}
			}
		}
		void delete_ticket(int id)
		{
			if(head==NULL)
			{
				return;
			}
			if(head->data.id==id)
			{
				delete_beg();
				return;
			}
			else{
				node * i=head;
			    while(i->next->data.id!=id)
			    {
				i=i->next;
		    	}
		    	i->next=i->next->next;
		    	return;
			}
			cout<<"Ticket Not Found!"<<endl;
			
		}
		void delete__specific(string start)
		{
			if(head==NULL)
			{
				return;
			}
			else if(head->data.end_station==start)
			{
				delete_beg();
				return;
			}
			else
			{
				node* i=head;
			while(i->next!=NULL)
			{
			    if(i->next->data.end_station==start)
				{
				   i->next=i->next->next;
				}
				i=i->next;
			}
			}
			
			
		}
		void delete_specific(string start)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->data.end_station == start)
    {
        delete_beg();
        return;
    }
    else
    {
        node* i = head;
        while (i->next != NULL)
        {
            if (i->next->data.end_station == start)
            {
                node* temp = i->next;
                i->next = temp->next;
                return;
            }
            i = i->next;
        }
    }
}

		void display()
		{
			node* i=head;
			if(head==NULL)
			{
				cout<<"\n\t\t.No Tickets to Show."<<endl;
				return;
			}
			while(i->next!=NULL)
			{
				i->data.display();
				i=i->next;
			}
			i->data.display();
		}
		void in_train(string start);
		
}list1,train;
void list::in_train(string start)
{
	node* i=head;
	if(head==NULL)
	{
		cout<<"\n\t\t.No Tickets to Show."<<endl;
		return;
	}
	while(i->next!=NULL)
	{
		if(i->data.start_station==start)
		{
			train.insert_beg(i->data);
		}
		i=i->next;
	}
	if(i->data.start_station==start)
	{
		train.insert_beg(i->data);
	}
	getch();	
}
class doubly_list
{
	struct node
	{
		Station data;
		node* prev;
		node* next;
		node()
		{
		   prev=NULL;
		   next=NULL;
		}
	};
	
	public:
		node* head;
		node* i;
		void insert_beg(Station x)
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
		void insert_end(Station x)
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
				cout<<i->data.name<<" ";
				i=i->next;
			}
			cout<<i->data.name<<" "<<endl;
			while(i->prev!=NULL)
			{
				cout<<i->data.name<<" ";
				i=i->prev;
			}
			cout<<i->data.name<<" "<<endl;
		}
}d_list;
int total_tickets=0;
int check=0;
void train_animation(bool &flag,bool &flag1,Station &start,Station &end)
{
	if(flag1==true)
	{
		if(d_list.i->next!=NULL && flag==true)
		{
		    start=d_list.i->data;
			end=d_list.i->next->data;
			d_list.i=d_list.i->next;
		}
		else if(d_list.i->prev!=NULL)
		{
		    flag=false;
			start=d_list.i->data;
			end=d_list.i->prev->data;
			d_list.i=d_list.i->prev;
		}
		else
		{
		    cout<<".Train Engine is Being Changed."<<endl;
			cout<<".      Please Try Again       ."<<endl;
			getch();
			flag=true;
			return;
		}
		//list1.in_train(start.name);
		list1.delete_specific(start.name);
	}
	char choice;
	system("cls");
	cout<<"\t\t\t----- Manage Train Traveling ----"<<endl<<endl;
	cout<<"      ______________                                          ________________"<<endl;
	cout<<"     /              \\                                        /                \\"<<endl;
	cout<<"    /________________\\                                      /__________________\\"<<endl;
    cout<<"    |    STATION     |--------------------------------------|      STATION     |----->"<<endl;
	cout<<"      "<<start.name<<"-";
	if(start.id<end.id)
	{
	    cout<<start.route1_time;
	}
	else
	{
		cout<<start.route2_time;
	}
	cout<<"                                            ";
	cout<<"   "<<end.name<<"-";
	if(start.id<end.id)
	{
	    cout<<end.route1_time;
	}
	else
	{
		cout<<end.route2_time;
	}
	cout<<" "<<endl;
	cout<<"    ------------------                                      --------------------"<<endl;
	cout<<"__________________________"<<endl;
	cout<<"|______________| TRAIN |_|"<<endl;
	cout<<"0_0-----0_0-----0_0---0__0"<<endl;
	cout<<"------------------------------------------------------------------------------------->"<<endl<<endl<<endl;
	
	cout<<"Train is at "<<start.name<<" Station"<<endl;
	cout<<"Time : ";
	if(start.id<end.id)
	{
	    cout<<start.route1_time;
	}
	else
	{
		cout<<start.route2_time;
	}
	cout<<endl;
	cout<<"\n--- Select ---"<<endl<<endl;
	cout<<"1.Move Train To Next Station"<<endl;
	//cout<<"2.View Passenger in Train"<<endl;
	cout<<"0.Exit"<<endl;
	cout<<"Choice : ";
	cin>>choice;
	switch(choice)
	{
		case '1':
			flag1=true;
			break;
		case '2':
			system("cls");
			flag1=false;
			train.display();
			getch();
			break;
		case '0':
			flag1=false;
			break;
		default:
			cout<<"Invalid Choice"<<endl;
			break;
	}
	if(choice=='1')
	{
	int i=1;
	while(i<=57)
	{
		system("cls");
		cout<<"\t\t\t----- Manage Train Traveling ----"<<endl<<endl;
		cout<<"      ______________                                          ________________"<<endl;
		cout<<"     /              \\                                        /                \\"<<endl;
		cout<<"    /________________\\                                      /__________________\\"<<endl;
		cout<<"    |    STATION     |--------------------------------------|      STATION     |----->"<<endl;
		cout<<"      "<<start.name<<"-";
		if(start.id<end.id)
		{
		    cout<<start.route1_time;
		}
		else
		{
			cout<<start.route2_time;
		}
		cout<<"                                            ";
		cout<<"   "<<end.name<<"-";
		if(start.id<end.id)
		{
		    cout<<end.route1_time;
		}
		else
		{
			cout<<end.route2_time;
		}
		cout<<" "<<endl;
		cout<<"    ------------------                                      --------------------"<<endl;
		//cout<<"------------------------------------------------------------------------------------->"<<endl;
		for(int ind=0;ind<=i;ind++)
		{
			cout<<" ";
		}
	cout<<"__________________________"<<endl;
	for(int ind=0;ind<=i;ind++)
		{
			cout<<" ";
		}
	cout<<"|______________| TRAIN |_|"<<endl;
	for(int ind=0;ind<=i;ind++)
		{
			cout<<" ";
		}
	cout<<"0_0-----0_0-----0_0---0__0"<<endl;
	cout<<"------------------------------------------------------------------------------------->"<<endl;
	i++;
	
	Sleep(50);
    }
    cout<<"\n\n\t\tTRAIN reached "<<end.name<<" Station successfully!"<<endl;
    getch();
    }
}
void route();
int main()
{
	bool flag=true,flag1=true;
	Station start,end;
	int cancel_id;
	///Station Stack Values///
	s[0].id=1;
	s[0].name="Lahore";
	s[0].route1_time="8AM";
	s[0].route2_time="8AM";
	s[1].id=2;
	s[1].name="Multan";
	s[1].route1_time="12AM";
	s[1].route2_time="4AM";
	s[2].id=3;
	s[2].name="Islamabad";
	s[2].route1_time="4PM";
	s[2].route2_time="12PM";
	s[3].id=4;
	s[3].name="Karachi";
	s[3].route1_time="8PM";
	s[3].route2_time="8PM";
	/////////////////////////
	for(int i=0;i<4;i++)
	{
		d_list.insert_end(s[i]);
	}
	d_list.i=d_list.head;
	//d_list.display();
	char choice;
	do
	{
		system("cls");
		cout<<"============================="<<endl;
		cout<<"|  Train Management System  |"<<endl;
		cout<<"============================="<<endl<<endl;
		cout<<"-- Select --"<<endl;
		cout<<"1.Manager Menu"<<endl;
		cout<<"2.Passenger Menu"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"\n\tChoice : ";
		cin>>choice;
		switch(choice)
		{
			case '1':
				char manager_choice;
				do
				{
					system("cls");
					cout<<"============================="<<endl;
					cout<<"|  Train Management System  |"<<endl;
					cout<<"============================="<<endl<<endl;
					cout<<"-- Manager Menu --"<<endl<<endl;
					cout<<"1.Manage Train Traveling ---*_*---"<<endl;
					cout<<"2.Show Tickets"<<endl;
					cout<<"3.Search Ticket"<<endl;
					cout<<"4.Show Train Route & Time"<<endl;
					cout<<"0.Exit"<<endl;
					cout<<"\n\tChoice : ";
					cin>>manager_choice;
					switch(manager_choice)
					{
						case '1':
							system("cls");
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							cout<<"-- Manage Train Traveling --"<<endl<<endl;
							train_animation(flag,flag1,start,end);
							break;
						case '2':
							system("cls");
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							cout<<"\t\t--- All Tickets ---"<<endl;
							list1.display();
							getch();
							break;
						case '3':
							system("cls");
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							cout<<"\t\t--- Search Tickets ---"<<endl;
							list1.search();
							getch();
							break;
						case '4':
							system("cls");
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							route();
							getch();
							break;
						case '0':
							break;
						default:
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							cout<<"\n--- Invalid Choice ---"<<endl;
							break;
					}
				}while(manager_choice!='0');
				break;
			case '2':
				char passenger_choice;
				do
				{
					system("cls");
					cout<<"-- Passeneger Menu --"<<endl<<endl;
					cout<<"1.Book Ticket"<<endl;
					cout<<"2.Cancel Ticket"<<endl;
					cout<<"3.Show Train Route & Time & Fare"<<endl;
					cout<<"0.Exit"<<endl;
					cout<<"\n\tChoice : ";
					cin>>passenger_choice;
					switch(passenger_choice)
					{
						case '1':
							system("cls");
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							cout<<"--- Book Ticket ---"<<endl<<endl;
							t.input();
							//cout<<"CHECK"<<endl;
							//getch();
							list1.insert_end(t);
							break;
						case '2':
							system("cls");
							
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							cout<<"--- Cancel Ticket ---"<<endl;
							list1.display();
							cout<<"Enter Ticket_ID you want to Delete : ";
							cin>>cancel_id;
							list1.delete_ticket(cancel_id);
							break;
						case '3':
							system("cls");
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							route();
							getch();
							break;
						case '0':
						    break;
						default:
							cout<<"============================="<<endl;
							cout<<"|  Train Management System  |"<<endl;
							cout<<"============================="<<endl<<endl;
							cout<<"\n--- Invalid Choice ---"<<endl;
							break;
					}
				}while(passenger_choice!='0');
				break;
			case '0':
				break;
			default:
				cout<<"============================="<<endl;
				cout<<"|  Train Management System  |"<<endl;
				cout<<"============================="<<endl<<endl;
				cout<<"\n--- Invalid Choice ---"<<endl;
				break;
				
		}
	}while(choice!='0');
}
void Ticket::input()
{
	cin.ignore();
	id=++total_tickets;
	cout<<"ID : "<<id<<endl;
	cout<<"NAME : ";
	getline(cin,name);
	cout<<"PHONE_NO : ";
	getline(cin,phone_no);
	cout<<"-- Select Type -- "<<endl;
	cout<<"1.Economy Class"<<endl;
	cout<<"2.Buisness Class"<<endl;
	int type_choice;
	cout<<"Choice : ";
	cin>>type_choice;
	if(type_choice==1)
	{
		type="Economy Class";
		fare=1000;
	}
	else if(type_choice==2)
	{
		fare=1500;
		type="Buisness Class";
	}
	else
	{
		fare=1000;
		type="Economy Class";
	}
    start_select:///Goto Jumps Here
    system("cls");
    cout<<"-- Select Start --"<<endl;
	cout<<"1.Lahore"<<endl;
	cout<<"2.Multan"<<endl;
	cout<<"3.Islamabad"<<endl;
	cout<<"4.Karachi"<<endl;
	int start_choice;
	cout<<"Choice : ";
	cin>>start_choice;
	if(start_choice==1)
	{
		start_station="Lahore";
	}
	else if(start_choice==2)
	{
		start_station="Multan";
	}
	else if(start_choice==3)
	{
		start_station="Islamabad";
	}
	else if(start_choice==4)
	{
		start_station="Karachi";
	}
	else
	{
		cout<<"\nInvalid Choice"<<endl;
		getch();
		goto start_select;///Goto Statement
	}
	end_select:///Goto Jumps Here
	system("cls");
	cout<<"-- Select End --"<<endl;
	cout<<"1.Lahore"<<endl;
	cout<<"2.Multan"<<endl;
	cout<<"3.Islamabad"<<endl;
	cout<<"4.Karachi"<<endl;
	int end_choice;
	cout<<"Choice : ";
	cin>>end_choice;
	if(end_choice==start_choice)
	{
		cout<<"\nSelect Different Ending Station"<<endl;
		getch();
		goto end_select;
	}
	else if(end_choice==1)
	{
		end_station="Lahore";
	}
	else if(end_choice==2)
	{
		end_station="Multan";
	}
	else if(end_choice==3)
	{
		end_station="Islamabad";
	}
	else if(end_choice==4)
	{
		end_station="Karachi";
	}
	else
	{
		cout<<"\nInvalid Choice"<<endl;
		getch();
		goto end_select;///Goto Statement 
	}
	if(end_choice>start_choice)
	{
		fare=fare*(end_choice-start_choice);
		route_id=1;
		route="Lahore -> Karachi";
		if(start_choice==1)
		{
			time="8AM";
		}
		else if(start_choice==2)
		{
			time="12AM";
		}
		else if(start_choice==3)
		{
			time="4PM";
		}
		else
		{
			time="8PM";
		}
	}
	else if(start_choice>end_choice)
	{
		fare=fare*(start_choice-end_choice);
		route_id=2;
		route="Karachi -> Lahore";
		if(start_choice==1)
		{
			time="8AM";
		}
		else if(start_choice==2)
		{
			time="4AM";
		}
		else if(start_choice==3)
		{
			time="12PM";
		}
		else
		{
			time="8PM";
		}
	}
	else
	{
		fare=fare*(end_choice-start_choice);
		route_id=1;
		route="Lahore -> Karachi";
		if(start_choice==1)
		{
			time="8AM";
		}
		else if(start_choice==2)
		{
			time="12AM";
		}
		else if(start_choice==3)
		{
			time="4PM";
		}
		else
		{
			time="8PM";
		}
	}
	cout<<endl;
}
void Ticket::display()
{
	cout<<"-- Ticket "<<id<<" --"<<endl;
	cout<<"ID : "<<id<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"Phone_NO : "<<phone_no<<endl;
	cout<<"Type : "<<type<<endl;
	cout<<"From : "<<start_station<<" At "<<time<<endl;
	cout<<"To : "<<end_station<<endl;
	cout<<"Fare : "<<fare<<endl;
	cout<<"Route : "<<route<<endl<<endl;
	cout<<"============================="<<endl<<endl;
}
void route()
{
	cout<<"\n--- Train Route  ---"<<endl<<endl;
	cout<<"First Route : Lahore -> Multan -> Islamabad -> Karachi"<<endl;
	cout<<"Second Route : Karachi -> Islamabad -> Multan -> Lahore"<<endl;
	cout<<"\n\n--- Timing  ---"<<endl<<endl;
	cout<<"1.Lahore - Multan : 8AM - 12AM "<<endl;
	cout<<"2.Multan - Islamabad : 12AM - 4PM"<<endl;
	cout<<"3.Islamabad - Karachi : 4PM - 8PM"<<endl;
	cout<<"4.Karachi - Islamabad : 8PM - 12PM"<<endl;
	cout<<"5.Islamabad - Multan : 12PM - 4AM"<<endl;
	cout<<"6.Multan - Lahore : 4AM - 8AM"<<endl;
	cout<<"7.Repeat"<<endl;
	cout<<"\n\n--- Fare ---"<<endl<<endl;
	cout<<"Economy Class : 1000 per Station"<<endl;
	cout<<"Buisness Class : 1500 pe Station"<<endl;
}
