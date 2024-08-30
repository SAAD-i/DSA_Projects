#include <iostream>
#include <conio.h>
using namespace std;
struct route
{
	int fare;
	string start_station;
	string end_station;
	string timing;
	route()
	{
		fare = 0;
		start_station = "";
		end_station = "";
		timing = "";
	}
} r[6];
class Ticket
{
	int id;
	string type;
	string start_station;
	string end_station;
	int fare;
	string time;
public:
	string name;
	string phone_no;
	
	Ticket()
	{
		id = 0;
		name = "";
		phone_no = "";
		type = "";
		fare = 0;
		start_station = "";
		end_station = "";
		time = "";
	}
	void input();
	void display();
} ticket;
int total_tickets = 0;
int ticket_id = 1;
class List
{
	struct node
	{
		Ticket data;
		node *next;
		node()
		{
			next = NULL;
		}
	} *head;

public:
	void insert_beg(Ticket x)
	{
		node *new_node = new node;
		new_node->data = x;
		if (head == NULL)
		{
			head = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
	}
	void insert_end(Ticket x)
	{
		node *new_node = new node;
		new_node->data = x;
		node *i = head;
		if (head == NULL)
		{
			head = new_node;
		}
		else
		{
			while (i->next != NULL)
			{
				i = i->next;
			}
			i->next = new_node;
		}
	}
	void delete_beg()
	{
		head = head->next;
	}
	void delete_end()
	{
		node *i = head;
		while (i->next->next != NULL)
		{
			i = i->next;
		}
		i->next = NULL;
	}
	void delete_specific(string name, string phone_no)
	{
		if (head == NULL)
		{
			cout << "\nNo Ticket Found of Name: " << name << " and Phone No: " << phone_no << endl;
			return;
		}
		if (head->data.name == name && head->data.phone_no == phone_no)
		{
			delete_beg();
			cout << "\nTicket Canceled Successfully." << endl;
			return;
		}
		node *i = head;
		while (i->next != NULL)
		{
			if (i->next->data.name == name && i->next->data.phone_no == phone_no)
			{
				i->next = i->next->next;
				cout << "\nTicket Canceled Successfully." << endl;
				return;
			}
			i = i->next;
		}
		cout << "\nNo Ticket Found of Name: " << name << " and Phone No: " << phone_no << endl;
	}

	void display()
	{
		node *i = head;
		if (head == NULL)
		{
			cout << "\n.No Tickets to Show." << endl;
			return;
		}
		while (i->next != NULL)
		{
			i->data.display();
			i = i->next;
		}
		i->data.display();
	}
} list;
void route();
void show_route();
void show_timing();
void show_fare();
void cancel_ticket();
int main()
{
	route();
	char choice;
	do
	{
		system("cls");
		cout << "================================" << endl;
		cout << "|  Railway Reservation System  |" << endl;
		cout << "================================" << endl
			 << endl;
		cout << "--- Select ---" << endl;
		cout << "1.Show Route" << endl;
		cout << "2.Show Timing" << endl;
		cout << "3.Show Fare" << endl;
		cout << "4.Book Ticket" << endl;
		cout << "5.Show Tickets" << endl;
		cout << "6.Cancel Ticket" << endl;
		cout << "0.Exit" << endl;
		cout << "\n\tChoice : ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls");
			cout << "================================" << endl;
			cout << "|  Railway Reservation System  |" << endl;
			cout << "================================" << endl
				 << endl;
			cout << "--- Route ---" << endl
				 << endl;
			show_route();
			getch();
			break;
		case '2':
			system("cls");
			cout << "================================" << endl;
			cout << "|  Railway Reservation System  |" << endl;
			cout << "================================" << endl
				 << endl;
			cout << "--- Timing ---" << endl
				 << endl;
			show_timing();
			getch();
			break;
		case '3':
			system("cls");
			cout << "================================" << endl;
			cout << "|  Railway Reservation System  |" << endl;
			cout << "================================" << endl
				 << endl;
			cout << "--- Fare ---" << endl
				 << endl;
			show_fare();
			getch();
			break;
		case '4':
			system("cls");
			cout << "================================" << endl;
			cout << "|  Railway Reservation System  |" << endl;
			cout << "================================" << endl
				 << endl;
			cout << "--- Book Ticket ---" << endl
				 << endl;
			ticket.input();
			list.insert_end(ticket);
			total_tickets++;
			getch();
			break;
		case '5':
			system("cls");
			cout << "================================" << endl;
			cout << "|  Railway Reservation System  |" << endl;
			cout << "================================" << endl
				 << endl;
			cout << "--- All  Tickets ---" << endl
				 << endl;
			list.display();
			getch();
			break;
		case '6':
			system("cls");
			cout << "================================" << endl;
			cout << "|  Railway Reservation System  |" << endl;
			cout << "================================" << endl
				 << endl;
			cout << "--- Cancel Ticket ---" << endl
				 << endl;
			cancel_ticket();
			total_tickets--;
			getch();
			break;
		case '0':
			break;
		default:
			system("cls");
			cout << "================================" << endl;
			cout << "|  Railway Reservation System  |" << endl;
			cout << "================================" << endl
				 << endl;
			cout << "--- Invalid Choice ---" << endl;
			getch();
			break;
		}
	} while (choice != '0');
}
void route()
{
	r[0].start_station = "Lahore";
	r[0].end_station = "Multan";
	r[0].fare = 1000;
	r[0].timing = "8AM - 12AM";

	r[1].start_station = "Multan";
	r[1].end_station = "Lahore";
	r[1].fare = 1000;
	r[1].timing = "12AM - 4PM";

	r[2].start_station = "Lahore";
	r[2].end_station = "Karachi";
	r[2].fare = 3000;
	r[2].timing = "8AM - 8PM";

	r[3].start_station = "Karachi";
	r[3].end_station = "Lahore";
	r[3].fare = 3000;
	r[3].timing = "8PM - 8AM";

	r[4].start_station = "Multan";
	r[4].end_station = "Karachi";
	r[4].fare = 2000;
	r[4].timing = "12AM - 8PM";

	r[5].start_station = "Karachi";
	r[5].end_station = "Multan";
	r[5].fare = 2000;
	r[5].timing = "8PM - 4AM";
}
void show_route()
{
	for (int i = 0; i < 6; i++)
	{
		cout << "--Route " << i + 1 << "--" << endl;
		cout << "From " << r[i].start_station << " To " << r[i].end_station << endl
			 << endl;
	}
}
void show_timing()
{
	for (int i = 0; i < 6; i++)
	{
		cout << "--Route " << i + 1 << "--" << endl;
		cout << "From " << r[i].start_station << " To " << r[i].end_station << endl;
		cout << "Timing : " << r[i].timing << endl
			 << endl;
	}
}
void show_fare()
{
	for (int i = 0; i < 6; i++)
	{
		cout << "--Route " << i + 1 << "--" << endl;
		cout << "From " << r[i].start_station << " To " << r[i].end_station << endl;
		cout << "Fare : " << r[i].fare << endl;
		cout << "Timing : " << r[i].timing << endl
			 << endl;
	}
}
void cancel_ticket()
{
	cin.ignore();
	if (total_tickets >= 0)
	{

		string name, phone_no;
		cout << "Name : ";
		getline(cin, name);
		cout << "Phone NO : ";
		getline(cin, phone_no);
		list.delete_specific(name, phone_no);
	}
	else
	{
		cout << "\n.No Tickets To Cancel." << endl;
	}
}
void Ticket::input()
{
	cin.ignore();
	id = ticket_id++;
	cout << "ID : " << id << endl;
	cout << "NAME : ";
	getline(cin, name);
	cout << "PHONE_NO : ";
	getline(cin, phone_no);
	cout << "-- Select Type -- " << endl;
	cout << "1.Economy Class" << endl;
	cout << "2.Buisness Class" << endl;
	int type_choice;
	cout << "Choice : ";
	cin >> type_choice;
	if (type_choice == 1)
	{
		type = "Economy Class";
	}
	else if (type_choice == 2)
	{
		type = "Buisness Class";
	}
	else
	{
		type = "Economy Class";
	}
	int start_choice;
	while (true)
	{
		system("cls");
		cout << "-- Select Start --" << endl;
		cout << "1.Lahore" << endl;
		cout << "2.Multan" << endl;
		cout << "3.Karachi" << endl;
		cout << "Choice : ";
		cin >> start_choice;
		if (start_choice == 1)
		{
			start_station = "Lahore";
			break;
		}
		else if (start_choice == 2)
		{
			start_station = "Multan";
			break;
		}
		else if (start_choice == 3)
		{
			start_station = "Karachi";
			break;
		}
		else
		{
			cout << "\nInvalid Choice" << endl;
			getch();
		}
	}
	int end_choice;
	while (true)
	{
		system("cls");
		cout << "-- Select End --" << endl;
		cout << "1.Lahore" << endl;
		cout << "2.Multan" << endl;
		cout << "3.Karachi" << endl;
		cout << "Choice : ";
		cin >> end_choice;
		if (end_choice == start_choice)
		{
			cout << "\nSelect Different Ending Station" << endl;
			getch();
		}
		else if (end_choice == 1)
		{
			end_station = "Lahore";
			break;
		}
		else if (end_choice == 2)
		{
			end_station = "Multan";
			break;
		}
		else if (end_choice == 3)
		{
			end_station = "Karachi";
			break;
		}
		else
		{
			cout << "\nInvalid Choice" << endl;
			getch();
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (start_station == r[i].start_station && end_station == r[i].end_station)
		{
			time = r[i].timing;
			fare = r[i].fare;
			if (type == "Buisness Class")
			{
				fare = fare * 2;
			}
		}
	}
}
void Ticket::display()
{
	cout << "\n-- Ticket " << id << " --" << endl;
	cout << "ID : " << id << endl;
	cout << "Name : " << name << endl;
	cout << "Phone_NO : " << phone_no << endl;
	cout << "Type : " << type << endl;
	cout << "From : " << start_station << endl;
	cout << "To : " << end_station << endl;
	cout << "Time : " << time << endl;
	cout << "Fare : " << fare << endl;
	cout << "=============================" << endl
		 << endl;
}
