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

    int n, ta, da, tb, db;
    cin >> n >> ta >> da >> tb >> db;

    int resA = 0, resB = 0;
    for (int i = 0; i < n; i++) {
        resA += ta + da * i;
        resB += tb + db * i;
    }

    if (resA < resB)
        cout << "Alice";
    else if (resA == resB)
        cout << "=";
    else
        cout << "Bob";
}