#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    cin.ignore();
    
    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);

        for (int j = 0; j < s.size(); j++)
            s[j] = j ? tolower(s[j]) : toupper(s[j]);

        cout << s << "\n";
    }
}