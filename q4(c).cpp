#include<iostream>
using namespace std;

int main(){

    int r,c;
    cout<<"Enter rows and cols of matrix:";
    cin>>r>>c;

    int a[r][c],t[c][r];

    cout<<"Enter the elements:";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<0;j++)
        {
            t[j][i]=a[i][j];
        }
    }
    cout<<"Transpose Matrix:"<<endl;
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
             cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

