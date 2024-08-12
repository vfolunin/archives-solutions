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

    int ai = 0, sum = 0;
    for (int bi = 0; bi < b.size(); bi++) {
        if (ai < a.size() && a[ai] == b[bi]) {
            ai++;
            sum += bi;
        }
    }

    if (ai == a.size())
        cout << "YES\n" << sum;
    else
        cout << "NO\n";
}