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

    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << b;
}