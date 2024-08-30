#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year;
    Book* next;

    Book(string title, string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
        this->next = NULL;
    }
};

class Stack {
private:
    Book* top;

public:
    Stack() {
        top = NULL;
    }

    void push(Book* book) {
        if (top == NULL) {
            top = book;
        } else {
            book->next = top;
            top = book;
        }
    }

    Book* pop() {
        if (isEmpty()) {
            return NULL;
        }
        Book* temp = top;
        top = top->next;
        temp->next = NULL;
        return temp;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

class LinkedList {
private:
    Book* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addBook(string title, string author, int year) {
        Book* newBook = new Book(title, author, year);
        if (head == NULL) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout << "Book Added Successfully." << endl;
    }

    void displayBooks() {
        if (head == NULL) {
            cout << "No Books in the Library." << endl;
            return;
        }
        cout << "Books in the Library:" << endl;
        Book* temp = head;
        string currentAuthor = temp->author;
        Stack booksStack;

        while (temp != NULL) {
            if (temp->author == currentAuthor) {
                booksStack.push(temp);
            } else {
                while (!booksStack.isEmpty()) {
                    Book* book = booksStack.pop();
                    cout << "Title: " << book->title << endl;
                    cout << "Author: " << book->author << endl;
                    cout << "Year: " << book->year << endl;
                    cout << "---------------------" << endl;
                }
                booksStack.push(temp);
                currentAuthor = temp->author;
            }
            temp = temp->next;
        }

        // Print the remaining books in the stack
        while (!booksStack.isEmpty()) {
            Book* book = booksStack.pop();
            cout << "Title: " << book->title << endl;
            cout << "Author: " << book->author << endl;
            cout << "Year: " << book->year << endl;
            cout << "---------------------" << endl;
        }
    }

    void deleteBook(string title) {
        if (head == NULL) {
            cout << "No Books in the Library." << endl;
            return;
        }
        if (head->title == title) {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "Book Deleted Successfully." << endl;
            return;
        }
        Book* curr = head;
        Book* prev = NULL;
        while (curr != NULL && curr->title != title) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            cout << "Book Not Found." << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Book Deleted Successfully." << endl;
    }

    void updateBook(string title) {
        if (head == NULL) {
            cout << "No Books in the Library." << endl;
            return;
        }
        Book* temp = head;
        while (temp != NULL && temp->title != title) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Book Not Found." << endl;
            return;
        }
        cout << "Enter New Title: ";
        getline(cin, temp->title);
        cout << "Enter New Author: ";
        getline(cin, temp->author);
        cout << "Enter New Publication Year: ";
        cin >> temp->year;
        cin.ignore();
        cout << "Book Updated Successfully." << endl;
    }
};

void menu() {
    cout << "Library Management System" << endl;
    cout << "-------------------------" << endl;
    cout << "1. Add a Book" << endl;
    cout << "2. Display All Books" << endl;
    cout << "3. Delete a Book" << endl;
    cout << "4. Update a Book" << endl;
    cout << "5. Quit" << endl;
    cout << "-------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    LinkedList library;
    int choice;
    while (true) {
        menu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string title, author;
                int year;
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                cout << "Enter Publication Year: ";
                cin >> year;
                library.addBook(title, author, year);
                break;
            }
            case 2:
                library.displayBooks();
                break;
            case 3: {
                string title;
                cout << "Enter the Title of the Book to Delete: ";
                getline(cin, title);
                library.deleteBook(title);
                break;
            }
            case 4: {
                string title;
                cout << "Enter the Title of the Book to Update: ";
                getline(cin, title);
                library.updateBook(title);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }
}

