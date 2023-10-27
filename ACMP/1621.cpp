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

    int size;
    cin >> size;

    vector<int> pos, neg;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 0)
            pos.push_back(value);
        if (value < 0)
            neg.push_back(value);
    }

    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());

    cout << pos.size() / 2 + neg.size() / 2 << "\n";
    for (int i = pos.size() % 2; i < pos.size(); i += 2)
        cout << pos[i] << " " << pos[i + 1] << "\n";
    for (int i = neg.size() % 2; i < neg.size(); i += 2)
        cout << neg[i] << " " << neg[i + 1] << "\n";
}