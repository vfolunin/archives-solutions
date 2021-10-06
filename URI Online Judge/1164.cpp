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

    set<int> perfect = { 6, 28, 496, 8128, 33550336 };

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cout << p << (perfect.count(p) ? "" : " nao") << " eh perfecto\n";
    }
}