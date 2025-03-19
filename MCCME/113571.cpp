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

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] < b[i])
            a[i] = '#';
        else if (b[i] < a[i])
            b[i] = '#';
    }

    a.erase(remove(a.begin(), a.end(), '#'), a.end());
    b.erase(remove(b.begin(), b.end(), '#'), b.end());

    while (a.size() > 1 && a.back() == '0')
        a.pop_back();
    while (b.size() > 1 && b.back() == '0')
        b.pop_back();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.empty())
        a = "YODA";
    if (b.empty())
        b = "YODA";

    cout << a << "\n" << b;
}