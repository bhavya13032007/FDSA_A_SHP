#include<iostream>
using namespace std;

int main()
{
    int n, b;

    cout << "Enter the number of books: ";
    cin >> n;

    int A[n];

    cout << "Enter the book numbers in sorted order:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the book number to be searched: ";
    cin >> b;

    int start = 0;
    int endd = n - 1;

    while(start <= endd)
    {
        int mid = (start + endd) / 2;

        if(A[mid] == b)
        {
            cout << "Book found at position " << mid + 1 << endl;
            return 0;
        }
        else if(A[mid] > b)
        {
            endd = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << "Book not found." << endl;

    return 0;
}
