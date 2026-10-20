#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int choice, patient;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> patient;
            q.push(patient);
        } 
        else if (choice == 2) {
            if (q.empty()) {
                cout << "Error: Queue is empty" << endl;
            } else {
                q.pop();
            }
        }

        if (q.empty()) {
            cout << "Front: Empty" << endl;
        } else {
            cout << "Front: " << q.front() << endl;
        }
    }

    return 0;
}