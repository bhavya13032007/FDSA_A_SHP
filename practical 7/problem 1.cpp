#include <iostream>
using namespace std;

int main() {
    int n, choice, token;
    cin >> n;

    int q[100], front = 0, rear = -1, count = 0;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> token;

            if (count == n) {
                cout << "Error: Queue is full" << endl;
            } else {
                rear = (rear + 1) % n;
                q[rear] = token;
                count++;
            }
        } 
        else if (choice == 2) {
            if (count == 0) {
                cout << "Error: Queue is empty" << endl;
            } else {
                front = (front + 1) % n;
                count--;
            }
        }

        if (count == 0) {
            cout << "Front: Empty" << endl;
        } else {
            cout << "Front: " << q[front] << endl;
        }
    }

    return 0;
}