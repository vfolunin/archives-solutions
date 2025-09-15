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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> delta(size + 1);
    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        delta[l - 1]++;
        delta[r]--;
    }

    vector<int> a;
    int sum = 0;
    for (int i = 0; i < delta.size() - 1; i++) {
        sum += delta[i];
        a.push_back(sum);
    }

    sort(a.begin(), a.end());

    cout << a[a.size() / 2];
}