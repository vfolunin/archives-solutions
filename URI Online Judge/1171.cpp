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

    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }

    for (auto &[x, k] : count)
        cout << x << " aparece " << k << " vez(es)\n";
}