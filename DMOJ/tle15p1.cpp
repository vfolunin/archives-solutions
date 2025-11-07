#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int w, h;
    cin >> w >> h;

    vector<string> name(w);
    for (string &name : name)
        cin >> name;

    vector<int> score(w);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            score[x] += value;
        }
    }

    vector<int> order(w);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int l, int r) {
        return score[l] > score[r];
    });

    for (int i = 0; i < order.size(); i++)
        cout << 3 + i << ". " << name[order[i]] << "\n";
}