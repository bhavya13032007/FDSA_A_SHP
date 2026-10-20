#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int stack[100];
    int top = -1;

    int q;
    cin >> q;

    while (q--) {
        string operation;
        int value;

        cin >> operation;

        if (operation == "place") {
            cin >> value;

            if (top == n - 1) {
                cout << "Error: Stack Overflow" << endl;
            } else {
                top++;
                stack[top] = value;
                cout << "Top: " << stack[top] << endl;
            }
        }
        else if (operation == "take") {
            if (top == -1) {
                cout << "Error: Stack Underflow" << endl;
            } else {
                top--;
                if (top == -1)
                    cout << "Stack is empty" << endl;
                else
                    cout << "Top: " << stack[top] << endl;
            }
        }
    }

    return 0;
}
