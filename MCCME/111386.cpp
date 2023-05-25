#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n) {
    if (!n) {
        cout << 0;
        return;
    }

    cout << "[";
    rec(n - 1);
    cout << ", ";
    rec(n - 1);
    cout << "]";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    rec(n);
}