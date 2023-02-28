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
     
    string a, b;
    cin >> a >> b;
    a += b;

    bool found = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (a.find(c) == -1 && a.find(tolower(c)) == -1) {
            cout << c;
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}