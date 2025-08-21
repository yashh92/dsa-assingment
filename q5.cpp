#include<iostream>
using namespace std;
int main(){

    int r,c;
    cout<<"Enter number of rows and cols:";
    cin>>r>>c;

    int a[10][10];
    cout<<"Enter the elements of matrix:"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
        // sum of each row
    for(int i=0;i<r;i++)
    {
        int rowsum=0;
        for(int j=0;j<c;j++)
        {
            rowsum+=a[i][j];
        }
        cout<<"Sum of row "<<i+1<<" = "<<rowsum<<endl;
    }

    // sum of each column
    for(int j=0;j<c;j++)
    {
        int colsum=0;
        for(int i=0;i<r;i++)
        {
            colsum+=a[i][j];
        }
        cout<<"Sum of column "<<j+1<<" = "<<colsum<<endl;
    }

    return 0;
}

   
