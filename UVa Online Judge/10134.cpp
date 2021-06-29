#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int baitCount = 0, fishCount = 0;
    int opSinceLastFish = -1, fishSinceLastFish = -1;

    while (1) {
        string op;
        if (!getline(cin, op) || op == "")
            break;

        if (opSinceLastFish != -1)
            opSinceLastFish++;

        if (op == "fish") {
            if (baitCount >= 2) {
                if (fishSinceLastFish != -1)
                    fishSinceLastFish++;

                if (!fishCount || opSinceLastFish >= 7 && fishSinceLastFish >= 3) {
                    baitCount -= 2;
                    fishCount++;
                    opSinceLastFish = 0;
                    fishSinceLastFish = 0;
                }
            }
        } else if (op == "bait") {
            baitCount = min(baitCount + 1, 6);
        }
    }

    if (test)
        cout << "\n";
    cout << fishCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}