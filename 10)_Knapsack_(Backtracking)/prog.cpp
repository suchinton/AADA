#include<iostream>
#include<vector>

using namespace std;

int weights[] = {2, 3, 4, 5}, values[] = {3, 4, 5, 6};

int solution = 0, n = 4;

std::vector<int> vsol;
std::vector<int> temp;

bool issol;

void Knapsack (int i, int max, int value)
{
  for (int k = i; k < n; k++) {
    if ( max > 0)
    {
        if (weights[k] <= max)
        {
          temp.push_back(k);
          if (value+ values[k] >= solution)
          {
            solution = value + values[k];
            issol = true;
          }
        }
        if ( (k+1) < n)
        {
          Knapsack (k+1, max - weights[k], value + values[k]);
        }
        else
        {
          if (issol == true)
          {
            if (! vsol.empty()) vsol.clear();
            std::move(temp.begin(), temp.end(), std::back_inserter(vsol));
            temp.clear();
            issol = false;
          } else temp.clear();
          return;
        }
    }
    else
    {
        if (issol == true)
        {
            if (! vsol.empty()) vsol.clear();
            std::move(temp.begin(), temp.end(), std::back_inserter(vsol));
            temp.clear();
            issol = false;
        } else temp.clear();
        return;
    }
  }
}

int main()
{
    system ("clear");

    printf("\n| Suchinton (A2345920063)               |");
    printf("\n|---------------------------------------|");
    printf("\n| 0-1 Knapsack Prob. using Backtracking |");
    printf("\n|---------------------------------------|\n");
    
    int KV = 21; //Knapsack value

    cout<<"\n| Ino. | W | V |\n";
    for(int i=0; i<n; i++)
      cout<<"|  "<<i+1<<"   | "<<weights[i]<<" | "<<values[i]<<" |\n";

    cout<<"\nn: "<<n;
    cout<<"\nKnapsack value: "<<KV;


    Knapsack(0, KV, 0);
    cout << "\nsolution: " << solution;
    cout << "\nItems:  ";
    for(vector<int>::iterator it = vsol.begin(); it != vsol.end(); it++)
        cout << *it + 1<< " ";
    return 0;
}