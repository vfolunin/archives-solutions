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
    int count;
    cin >> a >> b >> a >> b >> count;

    reverse(a.begin(), a.end());

    if (count < a.size())
        b = string(a.size() - count, ' ') + b;
    else if (count > a.size())
        a = string(count - a.size(), ' ') + a;

    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < b.size() && b[i] != ' ')
            cout << b[i];
        if (i < a.size() && a[i] != ' ')
            cout << a[i];
    }
}