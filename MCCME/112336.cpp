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
    cin >> s;

    int replaceCount = 0;
    for (char &c : s) {
        if (c == 'a') {
            c = 'b';
            replaceCount++;
        }
    }

    cout << s << "\n" << replaceCount;
}