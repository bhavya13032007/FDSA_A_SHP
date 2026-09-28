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

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteValue(int value) {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Patient not found" << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reverseDisplay(Node* temp) {
        if (temp == NULL) {
            return;
        }

        reverseDisplay(temp->next);
        cout << temp->data << " ";
    }

    void showReverse() {
        reverseDisplay(head);
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(101);
    list.insertEnd(102);
    list.insertEnd(103);
    list.insertEnd(104);
    list.insertEnd(105);

    cout << "Queue: ";
    list.display();

    list.deleteValue(103);

    cout << "After deleting 103: ";
    list.display();

    cout << "Reverse order: ";
    list.showReverse();

    cout << "Forward order: ";
    list.display();

    return 0;
}