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

    vector<pair<int, int>> a(size);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int sum = 0, bestSum = -1, bestL, bestR;
    for (int l = 0, r = 0; r < a.size(); r++) {
        sum += a[r].first;
        while (l + 1 < r && a[l].first + a[l + 1].first < a[r].first)
            sum -= a[l++].first;

        if (bestSum < sum) {
            bestSum = sum;
            bestL = l;
            bestR = r;
        }
    }

    cout << bestR - bestL + 1 << " " << bestSum << "\n";
    for (int i = bestL; i <= bestR; i++)
        cout << a[i].second + 1 << "\n";
}