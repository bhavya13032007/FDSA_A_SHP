#include<iostream>
using namespace std;

int main()
{
    int n, b ,g;

    cout << "Enter the number of cars: ";
    cin >> n;

    int A[n];

    cout << "Enter the car numbers:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the car number to be searched: ";
    cin >> b;
    cout<<"Enter the number of cars to be searched by guard"<<endl;
    cin>>g;

    int i;
    for(i = 0; i < g; i++)
    {
        if(A[i] == b)
        {
            cout << "Car found at parking position(by guard) " << i + 1 << endl;
            break;
        }

    }

    for(int i=g;i<n;i++)
    {
     if(A[i] == b)
        {
            cout << "Car found at parking position(by helper) " << i + 1 << endl;
            break;
        }

    }

    if(i == n)
    {
        cout << "No car found with this number." << endl;
    }

    return 0;
}
