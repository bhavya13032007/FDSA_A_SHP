#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int a[n];

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    int k = h % n;

    cout << "Final display order: ";


    for (int i = k; i < n; i++)
    {
        cout << a[i] << " ";
    }


    for (int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
