#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> shelf[10];
    int n, code;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> code;
        int index = code % 10;
        shelf[index].push_back(code);
    }

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        for (int code : shelf[i]) {
            cout << code << " ";
        }

        cout << endl;
    }

    return 0;
}