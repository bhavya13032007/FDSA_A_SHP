#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;

    int a[n];

    cout << "Enter Book IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Book IDs borrowed more than once are: ";

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            bool printed = false;

            for (int k = 0; k < i; k++)
            {
                if (a[k] == a[i])
                {
                    printed = true;
                    break;
                }
            }

            if (!printed)
            {
                cout << a[i] << " ";
            }
        }
    }

    return 0;
}

