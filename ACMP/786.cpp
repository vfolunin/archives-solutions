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

    vector<int> winMove = { 0, 0 };
    int last0 = 2;

    for (int i = 2; i <= n; i++) {
        if (i < 2 * last0) {
            winMove.push_back(i - last0);
        } else {
            winMove.push_back(0);
            last0 = i;
        }
    }

    cout << winMove[n];
}