#include <iostream>

using namespace std;

int main()
{
    string s = "";
    string a = "abcd";
    for(int i=0; i<4; i++)
    {
        s = s+a[i];
    }
    cout<<s;

    return 0;
}
