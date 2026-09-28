#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void selectionSort(vector<int>& a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

void insertionSort(vector<int>& a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void printArray(vector<int>& a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }

    bubbleSort(a, n);
    selectionSort(b, n);
    insertionSort(c, n);

    cout << "Bubble Sort: ";
    printArray(a, n);

    cout << "Selection Sort: ";
    printArray(b, n);

    cout << "Insertion Sort: ";
    printArray(c, n);

    return 0;
}