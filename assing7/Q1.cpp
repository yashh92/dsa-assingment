#include <iostream>
using namespace std;

void sel(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int m = i;
        for(int j = i + 1; j < n; j++)
        {
            m = a[j] < a[m] ? j : m;
        }
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void ins(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int v = a[i], j = i - 1;
        while(j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

void bub(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void merge_arr(int a[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int *x = new int[n1], *y = new int[n2];

    for(int i = 0; i < n1; i++)
    {
        x[i] = a[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        y[i] = a[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        a[k++] = x[i] <= y[j] ? x[i++] : y[j++];
    }
    while(i < n1)
    {
        a[k++] = x[i++];
    }
    while(j < n2)
    {
        a[k++] = y[j++];
    }

    delete[] x;
    delete[] y;
}

void merge_sort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge_arr(a, l, m, r);
    }
}

int part(int a[], int l, int r)
{
    int p = a[r], i = l - 1;
    for(int j = l; j < r; j++)
    {
        if(a[j] < p)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    return i + 1;
}

void quick_sort(int a[], int l, int r)
{
    if(l < r)
    {
        int pi = part(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}

void show(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, x;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sel(a, n);
    show(a, n);

    ins(a, n);
    show(a, n);

    bub(a, n);
    show(a, n);

    merge_sort(a, 0, n - 1);
    show(a, n);

    quick_sort(a, 0, n - 1);
    show(a, n);

    delete[] a;
}