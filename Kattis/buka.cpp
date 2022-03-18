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

    string a, op, b;
    cin >> a >> op >> b;

    if (op == "+") {
        if (a.size() == b.size()) {
            a[0]++;
        } else {
            if (a.size() < b.size())
                swap(a, b);
            a[a.size() - b.size()]++;
        }
        cout << a;
    } else {
        cout << "1" << string(a.size() + b.size() - 2, '0');
    }
}