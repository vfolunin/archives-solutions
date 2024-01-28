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

    string s;
    getline(cin, s);

    bool found = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            cout << i << " ";
            found = 1;
        }
    }
    
    if (!found)
        cout << -1;
}