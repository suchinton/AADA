
/* 
Given two sequences, a subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, „”acefg”, .. etc are subsequences of “abcdefg”.
So a string of length n has 2^n different possible subsequences. 
It is a classic computer science problem, the basis of file comparison programs and has applications in bioinformatics.
Develop a pro gram to implement the solution of Longest Common Sub-sequence problem.
 */

#include<bits/stdc++.h>
#include <iostream>

using namespace std;
  
int max(int a, int b);
  
/* Returns length of LCS */
int LCS(string Str1, string Str2, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;
    
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (Str1[i - 1] == Str2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
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
  
    printf("\nLength of LCS is %d\n", LCS(Str1, Str2, m, n));
  
    return 0;
}