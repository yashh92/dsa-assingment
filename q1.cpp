#include<iostream>
using namespace std;

int main()
{
    int arr[100], n=0, choice, pos, val, i, item;
    do
    {
        cout<<"\n--- MENU ---"<<endl;
        cout<<"1. CREATE"<<endl;
        cout<<"2. DISPLAY"<<endl;
        cout<<"3. INSERT"<<endl;
        cout<<"4. DELETE"<<endl;
        cout<<"5. LINEAR SEARCH"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter number of elements: ";
                cin>>n;
                cout<<"Enter elements: ";
                for(i=0;i<n;i++)
                    cin>>arr[i];
                break;

            case 2:
                cout<<"Array elements are: ";
                for(i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                cout<<endl;
                break;

            case 3:
                cout<<"Enter position to insert: ";
                cin>>pos;
                cout<<"Enter value to insert: ";
                cin>>val;
                if(pos<1 || pos>n+1)
                    cout<<"Invalid position!"<<endl;
                else
                {
                    for(i=n;i>=pos;i--)
                        arr[i]=arr[i-1];
                    arr[pos-1]=val;
                    n++;
                    cout<<"Element inserted."<<endl;
                }
                break;

            case 4:
                cout<<"Enter position to delete: ";
                cin>>pos;
                if(pos<1 || pos>n)
                    cout<<"Invalid position!"<<endl;
                else
                {
                    for(i=pos-1;i<n-1;i++)
                        arr[i]=arr[i+1];
                    n--;
                    cout<<"Element deleted."<<endl;
                }
                break;

            case 5:
                cout<<"Enter element to search: ";
                cin>>item;
                for(i=0;i<n;i++)
                {
                    if(arr[i]==item)
                    {
                        cout<<"Element found at position "<<i+1<<endl;
                        break;
                    }
                }
                if(i==n)
                    cout<<"Element not found."<<endl;
                break;

            case 6:
                cout<<"Exiting program..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }
    } while(choice!=6);

    return 0;
}
