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

    int prefix = 0;
    while (prefix < a.size() && prefix < b.size() && a[prefix] == b[prefix])
        prefix++;

    cout << a.size() + b.size() - 2 * prefix;
}