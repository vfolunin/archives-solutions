#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int presentCount, maxWeight;
    cin >> presentCount >> maxWeight;

    int res = 1, curWeight = 0;
    for (int i = 0; i < presentCount; i++) {
        int weight;
        cin >> weight;
        if (curWeight + weight <= maxWeight) {
            curWeight += weight;
        } else {
            curWeight = weight;
            res++;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}