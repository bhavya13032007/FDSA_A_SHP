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

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        display();
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            display();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        display();
    }

    void insertPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position <= 1) {
            newNode->next = head;
            head = newNode;
            display();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position is greater than the list length" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        display();
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(101);
    list.insertEnd(102);
    list.insertFront(100);
    list.insertPosition(105, 3);
    list.insertPosition(110, 10);

    return 0;
}