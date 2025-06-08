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

    int limit;
    string s;
    cin >> limit >> s;

    int depth = 0;
    for (char c : s) {
        depth += c == '(';
        if (depth <= limit)
            cout << c;
        depth -= c == ')';
    }
}