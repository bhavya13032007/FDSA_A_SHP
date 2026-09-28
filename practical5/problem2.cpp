#include <iostream>
#include <string>
using namespace std;

struct SNode {
    string name;
    SNode* next;
};

struct DNode {
    string name;
    DNode* next;
    DNode* prev;
};

void joinSingly(SNode*& head, string name, int pos) {
    SNode* newNode = new SNode{name, nullptr};

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    if (pos == 1) {
        SNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
    }

    SNode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void leaveSingly(SNode*& head, string name) {
    if (head == nullptr)
        return;

    SNode* current = head;
    SNode* previous = nullptr;

    do {
        if (current->name == name) {
            if (current == head) {
                SNode* last = head;
                while (last->next != head)
                    last = last->next;

                if (head->next == head)
                    head = nullptr;
                else {
                    head = head->next;
                    last->next = head;
                }
            } else {
                previous->next = current->next;
            }

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    } while (current != head);
}

void displaySingly(SNode* head) {
    if (head == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    SNode* temp = head;

    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

void joinDoubly(DNode*& head, string name, int pos) {
    DNode* newNode = new DNode{name, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    if (pos == 1) {
        DNode* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }

    DNode* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void leaveDoubly(DNode*& head, string name) {
    if (head == nullptr)
        return;

    DNode* temp = head;

    do {
        if (temp->name == name) {
            if (temp->next == temp) {
                head = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;
            }

            delete temp;
            return;
        }

        temp = temp->next;
    } while (temp != head);
}

void displayDoubly(DNode* head) {
    if (head == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    DNode* temp = head;

    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    SNode* singly = nullptr;
    DNode* doubly = nullptr;

    int q;
    cin >> q;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "join") {
            int pos;
            string name;
            cin >> pos >> name;

            joinSingly(singly, name, pos);
            joinDoubly(doubly, name, pos);

            cout << "Singly: ";
            displaySingly(singly);

            cout << "Doubly: ";
            displayDoubly(doubly);
        }
        else if (operation == "leave") {
            string name;
            cin >> name;

            leaveSingly(singly, name);
            leaveDoubly(doubly, name);

            cout << "Singly: ";
            displaySingly(singly);

            cout << "Doubly: ";
            displayDoubly(doubly);
        }
        else if (operation == "display") {
            cout << "Singly: ";
            displaySingly(singly);

            cout << "Doubly: ";
            displayDoubly(doubly);
        }
    }

    return 0;
}