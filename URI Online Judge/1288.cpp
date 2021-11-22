#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int itemCount;
    cin >> itemCount;

    vector<int> maxBonus(501, -1e9);
    maxBonus[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int bonus, weight;
        cin >> bonus >> weight;
        for (int w = 500; w >= weight; w--)
            if (maxBonus[w - weight] != -1e9)
                maxBonus[w] = max(maxBonus[w], maxBonus[w - weight] + bonus);
    }

    int maxWeight, targetBonus;
    cin >> maxWeight >> targetBonus;

    if (*max_element(maxBonus.begin(), maxBonus.begin() + maxWeight + 1) >= targetBonus)
        cout << "Missao completada com sucesso\n";
    else
        cout << "Falha na missao\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}