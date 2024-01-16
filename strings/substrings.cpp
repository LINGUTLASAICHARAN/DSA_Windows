#include<bits/stdc++.h>

using namespace std;

int main() {

    string s = "abcdef";
    int size = s.size();
    cout << "splitting the string at position i\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << s.substr(0, i + 1) <<"  " << s.substr(i + 1, size - i - 1) << endl;
    }
    
    cout << endl << "pattern 2: removing the character at position i\n\n";
    
    for (int i = 0; i < size; i++)
    {
        cout << s.substr(0, i ) <<"  " << s.substr(i + 1, size - i - 1) << endl;
    }
    }