#include<iostream>
#include <unistd.h>
#include <time.h>
using namespace std;
int liner_search(int arr[], int len, int search);

int main()
{
    int len;
    int search;
    clock_t begin, halt;

    system("clear");
    printf("\n| Suchinton (A2345920063)  |");
    printf("\n|--------------------------|");
    printf("\n|Linear Search             |");
    printf("\n|--------------------------|");

    cout<<"\n\nEnter no. of elements : ";
    cin>>len;

    int Arr[len];

    for(int i=0; i<len; i++ )
    {
        cout<<"element "<<i+1<<": ";
        scanf("%d",&Arr[i]);
    }

    cout<<"\nEntered array: \n";
    for(int i=0; i<len; i++ )
        cout<<Arr[i]<<" ";

    cout<<"\n\nEnter element to search: ";
    cin>>search;

    begin = clock();
    liner_search(Arr, len, search);
    halt = clock();
    printf("\nTime taken is %f CPU cycles \n\n",(float)(halt-begin)/CLOCKS_PER_SEC);
}

int liner_search(int arr[], int len, int search)
{
    int max = arr[0];
    int min = arr[0];
    int index = -1;

    for(int i=0; i<len; i++)
    {
        if(arr[i]==search)
        {
            index = i;
            cout<<"\nMatch found at index "<<index;
        }
        if(min > arr[i])
            min = arr[i];
        if(max <= arr[i])
            max = arr[i];
    }
    
    if(index == -1)
        cout<<"\nMatch not found";

    cout<<"\nMin element : "<<min;
    cout<<"\nMax element : "<<max<<endl;

    return 0;
}