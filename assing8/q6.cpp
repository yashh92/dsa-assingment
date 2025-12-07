#include <iostream>
using namespace std;

void heapifyUp(int a[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (a[parent] < a[index]) {
            int temp = a[parent];
            a[parent] = a[index];
            a[index] = temp;
            index = parent;
        } else
            break;
    }
}

void heapifyDown(int a[], int n, int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;

        if (largest != index) {
            int temp = a[index];
            a[index] = a[largest];
            a[largest] = temp;
            index = largest;
        } else
            break;
    }
}

void insertPQ(int a[], int &size, int val) {
    a[size] = val;
    heapifyUp(a, size);
    size++;
}

int getMax(int a[], int size) {
    if (size == 0) return -1;
    return a[0];
}

int deleteMax(int a[], int &size) {
    if (size == 0) return -1;
    int maxVal = a[0];
    a[0] = a[size - 1];
    size--;
    heapifyDown(a, size, 0);
    return maxVal;
}

void displayPQ(int a[], int size) {
    if (size == 0) {
        cout << "Priority queue is empty\n";
        return;
    }
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[100];
    int size = 0;
    int choice = -1;

    while (choice != 0) {
        cout << "\n1. Insert\n2. Get max\n3. Delete max\n4. Display\n0. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int x;
            cout << "Enter value: ";
            cin >> x;
            insertPQ(a, size, x);
        }
        else if (choice == 2) {
            int mx = getMax(a, size);
            if (mx == -1) cout << "Priority queue is empty\n";
            else cout << "Max element: " << mx << endl;
        }
        else if (choice == 3) {
            int mx = deleteMax(a, size);
            if (mx == -1) cout << "Priority queue is empty\n";
            else cout << "Deleted max: " << mx << endl;
        }
        else if (choice == 4) {
            displayPQ(a, size);
        }
        else if (choice == 0) {
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
