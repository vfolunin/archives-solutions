#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n, bits;
    cin >> n >> bits;

    vector<int> gray = { 0 };
    for (int i = 0; i < n; i++) {
        gray.resize(gray.size() * 2);
        for (int j = gray.size() / 2; j < gray.size(); j++)
            gray[j] = (1 << i) | gray[gray.size() - 1 - j];
    }

    int val = 0;
    for (int i = 0; i < bits; i++) {
        int bit;
        cin >> bit;
        val |= (1 << (bit - 1));
    }

    int pos = find(gray.begin(), gray.end(), val) - gray.begin();
    for (int i = 1; i < gray.size(); i++) {
        int bit = 0;
        while ((gray[pos] & (1 << bit)) == (gray[(pos + 1) % gray.size()] & (1 << bit)))
            bit++;
        if (gray[pos] & (1 << bit))
            cout << "Move " << bit + 1 << " from B1 to B2\n";
        else
            cout << "Move " << bit + 1 << " from B2 to B1\n";
        pos = (pos + 1) % gray.size();
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}