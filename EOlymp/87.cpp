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
    
    string ops;
    cin >> ops;

    int x = 0, l = 0, r = 0;
    for (char op : ops) {
        x -= op == 'L';
        x += op == 'R';

        l = min(l, x);
        r = max(r, x);
    }

    cout << r - l + 1;
}