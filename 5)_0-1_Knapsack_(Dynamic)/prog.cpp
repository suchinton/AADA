#include <bits/stdc++.h>
using namespace std;
#include <time.h>

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
   if (n == 0 || W == 0)
      return 0;

   if (wt[n - 1] > W)
      return knapSack(W, wt, val, n - 1);
   else
      return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}
 
int main()
{
   clock_t begin, halt;
   system ("clear");

   printf("\n| Suchinton (A2345920063) |");
   printf("\n|-----------------------------|");
   printf("\n| WAP to implement Quick Sort |");
   printf("\n|-----------------------------|\n");
   
   cout << "Enter the number of items in a Knapsack:";
   int n, W;
   cin >> n;
   int v[n], w[n];
   for (int i = 0; i < n; i++) 
   {
      cout << "Enter value and weight for item " << i << ":\n";
      cout << "value: ";
      cin >> v[i];
      cout << "weight: ";
      cin >> w[i];
   }
   cout << "Enter the capacity of knapsack";
   cin >> W;

   cout << knapSack(W, w, v, n);
   halt = clock();
   printf("\nTime taken is %f CPU cycles \n\n",(float)(halt-begin)/CLOCKS_PER_SEC);
   return 0;
}