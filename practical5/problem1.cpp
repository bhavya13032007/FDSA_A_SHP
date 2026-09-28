#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        display();
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        display();
    }

    void insertAfter(string givenSong, string newSong) {
        Node* temp = head;

        while (temp != NULL && temp->song != givenSong) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found" << endl;
            return;
        }

        Node* newNode = new Node(newSong);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;

        display();
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty" << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        display();
    }

    void countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Number of songs: " << count << endl;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Playlist p;

    p.addEnd("Song1");
    p.addEnd("Song2");
    p.addBeginning("Song0");
    p.insertAfter("Song1", "Song1.5");
    p.removeFirst();
    p.countSongs();

    return 0;
}