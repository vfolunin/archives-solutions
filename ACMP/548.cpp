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

    a.push_back('9');
    b.push_back('9');

    for (int ai = 0, bi = 0; ai + 1 < a.size() || bi + 1 < b.size(); ) {
        if (bi + 1 == b.size() || ai + 1 < a.size() && a.substr(ai) < b.substr(bi))
            cout << a[ai++];
        else
            cout << b[bi++];
    }
}