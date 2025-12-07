#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left, maxIndex = left;

        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        int temp = a[left];
        a[left] = a[minIndex];
        a[minIndex] = temp;

        if (maxIndex == left)
            maxIndex = minIndex;

        temp = a[right];
        a[right] = a[maxIndex];
        a[maxIndex] = temp;

        left++;
        right--;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    improvedSelectionSort(a, n);
    printArray(a, n);

    return 0;
}
