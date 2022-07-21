#include<iostream>
#include <unistd.h>

using namespace std;

int binarySearch(int A[],int l,int r,int search);

 int main()
   {
      system("clear");
      printf("\n| Suchinton (A2345920063)            |");
      printf("\n|------------------------------------|");

      printf("\n|Binary_search-[enter sorted elements|");
      printf("\n|------------------------------------|");

      int len, search,result;
      printf("\nEnter no. of elements you wish to enter: ");
      scanf("%d",&len);

      int A[len];

      for(int i=0;i<len;i++)
         {
            printf("Element %d is: ",i+1);
            scanf("%d",&A[i]);
         }

      //system("clear");

      printf("\n\nEntered array is: \n");
      for(int i=0;i<len;i++)
         printf("%d ",A[i]);

      printf("\n\nenter the element to search: ");
      scanf("%d",&search);

      result = binarySearch(A, 0, len - 1, search);
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
   }

int binarySearch(int A[],int l,int r,int search)
   {
      if (r >= l) {
         int mid = l + (r - l) / 2;

      if (A[mid] == search)
         return mid;

      if (A[mid] > search)
         return binarySearch(A, l, mid - 1, search);
      return binarySearch(A, mid + 1, r, search);
   }
  
}