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

    vector<int> a = { 0, 1 };
    for (int i = 2; i < 1e5; i += 2) {
        a.push_back(a[i / 2]);
        a.push_back(a[i / 2] + a[i / 2 + 1]);
    }

    for (int i = 1; i < a.size(); i++)
        a[i] = max(a[i], a[i - 1]);

    for (int index; cin >> index && index; )
        cout << a[index] << "\n";
}