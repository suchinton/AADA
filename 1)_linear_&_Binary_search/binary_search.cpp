#include<iostream>
#include <unistd.h>
#include <chrono>
#include <time.h>

using namespace std::chrono;
using namespace std;

int no_rec = 0;
int binarySearch(int A[],int l,int r,int search);

int main()
  {
     system("clear");
     printf("\n| Suchinton (A2345920063)            |");
     printf("\n|------------------------------------|");
     printf("\n|Binary_search-[enter sorted elements|");
     printf("\n|------------------------------------|");

     int len = 1000000;
     int search,result;
     clock_t begin, halt;

     printf("\nRange: 0-1000000");

     int A[len];

     for(int i=0;i<=len;i++)
        {
           A[i] = i;
        }

     printf("\n\nenter the element to search: ");
     scanf("%d",&search);

     auto start = high_resolution_clock::now();
     begin = clock();
     result = binarySearch(A, 0, len - 1, search);
     halt = clock();
     auto stop = high_resolution_clock::now();

     if(A[result] != search)
        printf("\nElement is not present in array\n");
     else if(A[result]==search && A[result+1]==search)
        {
           printf("\nElement is present at position %d",result+1);
           printf("\nElement is present at position %d",result+2);
        }
     else if(A[result]==search && A[result-1]==search)
        {
           printf("\nElement is present at position %d",result);
           printf("\nElement is present at position %d",result+1);
        }
     else if(A[result]==search)
        printf("\nElement is present at position %d\n",result+1);

     auto duration = duration_cast<microseconds>(stop - start);
     cout<<"Time taken: "<<duration.count()<<"ms"<<endl;
     cout<<"No. of recurssions: "<<no_rec;
     printf("\nTime taken is %f CPU cycles \n\n",(float)(halt-begin)/CLOCKS_PER_SEC);
  }

int binarySearch(int A[],int l,int r,int search)
   {
      no_rec += 1; 
      if (r >= l) {
         int mid = l + (r - l) / 2;

      if (A[mid] == search)
         return mid;

      if (A[mid] > search)
         return binarySearch(A, l, mid - 1, search);
      return binarySearch(A, mid + 1, r, search);
   }
}