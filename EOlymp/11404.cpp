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

    for (int i = 0; i < b.size(); i++)
        cout << a[i] << b[i];

    if (a.size() > b.size())
        cout << a.back();
}