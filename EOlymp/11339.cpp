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

    int n;
    cin >> n;

    vector<int> a, b;
    for (; n >= 4; n -= 4) {
        a.push_back(n);
        a.push_back(n - 3);
        b.push_back(n - 2);
        b.push_back(n - 1);
    }

    if (n == 3) {
        a.push_back(2);
        b.push_back(3);
    } else if (n == 2) {
        b.push_back(2);
    }
    if (n)
        a.push_back(1);

    cout << a.size() << " " << b.size() << "\n";
    for (int value : a)
        cout << value << " ";
    cout << "\n";
    for (int value : b)
        cout << value << " ";
}