#include<bits/stdc++.h>
#include <iostream>

using namespace std;
  
int max(int a, int b);

void reverseStr(string& str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
  
/* Returns length of LCS */
int LCS(string Str1, string Str2, int m, int n)
{
    //string seq="";
    int L[m + 1][n + 1];
    int i, j;
    
    for (i = 0; i <= m; i++) 
        for (j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (Str1[i - 1] == Str2[j - 1])
                {
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }

    /* printing DP table */
    cout<<"\n  |  ";
    for (i = 0; i <= n; i++)
    {
        if(i==0)
            cout<<" | ";
        else
            cout<<Str2[i-1]<<" | ";
    }

    for (i = 0; i <= m; i++) 
    {
        cout<<"\n";
        if(i==0)
            cout<<"  | ";
        else
            cout<<Str1[i-1]<<" | ";
        for (j = 0; j <= n; j++)
            cout<<L[i][j]<<" | ";
    }

    /* Tracing LCS */
    string seq;
    for(i = m; i > 0; i--)
    {
        for(j = n; j > 0; j--)
        {
            if (Str1[i-1]==Str2[j-1]) {
                seq = seq + Str1[i-1];
                cout<<"\nadded ["<<i<<"]["<<j<<"]";
                i--;
            }
            else if(L[i-1][j] > L[i][j-1])
            {
                i--;
                j++;
            }
            else
            {
                continue;
            }
        }
    }
    reverseStr(seq);
     
    cout<<"\nseq: "<<seq<<"\n";

    return L[m][n];
}
  
int max(int a, int b)
{
    return (a > b) ? a : b;
}
  
int main()
{
    system ("clear");

    printf("\n| Cherry    (A2345920063)                   |");
    printf("\n| Suchinton (A2345920063)                   |");
    printf("\n|-------------------------------------------|");
    printf("\n| WAP to implement LCS Algo. (Dynamic Prog.)|");
    printf("\n|-------------------------------------------|\n");

    string Str1;
    string Str2;

    cout<<"\nString 1: ";
    getline(cin,Str1);
    cout<<"String 2: ";
    getline(cin,Str2);

    int m = Str1.length();
    int n = Str2.length();

    printf("\n\nLength of LCS is %d\n", LCS(Str1, Str2, m, n));

    return 0;
}