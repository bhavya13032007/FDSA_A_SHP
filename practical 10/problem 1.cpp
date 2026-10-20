#include <iostream>
using namespace std;

int main() {
    int slots[10];
    int n, reg;

    for (int i = 0; i < 10; i++)
        slots[i] = -1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> reg;
        int index = reg % 10;
        int count = 0;

        while (slots[index] != -1 && count < 10) {
            index = (index + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking full for vehicle " << reg << endl;
        } else {
            slots[index] = reg;
        }
    }

    cout << "Final parking slots:\n";

    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        if (slots[i] == -1)
            cout << "Empty";
        else
            cout << slots[i];
        cout << endl;
    }

    return 0;
}