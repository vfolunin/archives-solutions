#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string ops;
    cin >> ops >> ops;

    string symbols = "ENWS";
    int index = 0;
    for (char op : ops)
        index = (index + (op == '1' ? 1 : 3)) % symbols.size();
    
    cout << symbols[index] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}