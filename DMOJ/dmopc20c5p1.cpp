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

    int size = 0;
    while (size < a.size() && size < b.size() && a[size] == b[size])
        size++;

    cout << a.size() + b.size() - 2 * size << "\n";
}