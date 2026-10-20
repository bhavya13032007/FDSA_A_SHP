#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> history;
    int q;
    cin >> q;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "visit") {
            string page;
            cin >> page;
            history.push_back(page);
            cout << "Current Page: " << history.back() << endl;
        }
        else if (operation == "back") {
            if (history.empty()) {
                cout << "Error: No previous page" << endl;
            }
            else {
                history.pop_back();

                if (history.empty())
                    cout << "No page" << endl;
                else
                    cout << "Current Page: " << history.back() << endl;
            }
        }
    }

    return 0;
}