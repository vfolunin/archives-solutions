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

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0;
        return 0;
    }

    if (a < b) {
        cout << "-";
        swap(a, b);
    }

    cout << string(a - b, '9') << string(b, '0');
}