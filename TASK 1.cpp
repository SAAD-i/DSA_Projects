#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;
    int sum;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
        sum = 0;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == NULL) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;

        count++;
        sum += value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue elements: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    double computeAverage() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return 0.0;
        }

        return static_cast<double>(sum) / count;
    }

private:
    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    double average = queue.computeAverage();
    cout << "Average value of elements in the queue: " << average << endl;

    return 0;
}

