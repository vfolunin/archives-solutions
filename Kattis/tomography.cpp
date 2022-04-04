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

    int h, w;
    cin >> h >> w;

    vector<int> rowSum(h);
    for (int &sum : rowSum)
        cin >> sum;
    sort(rowSum.rbegin(), rowSum.rend());

    vector<int> colSum(w);
    for (int &sum : colSum)
        cin >> sum;
    sort(colSum.rbegin(), colSum.rend());

    for (int sum : rowSum) {
        for (int i = 0; i < sum; i++)
            colSum[i]--;
        sort(colSum.rbegin(), colSum.rend());
    }

    cout << (count(colSum.begin(), colSum.end(), 0) == colSum.size() ? "Yes\n" : "No\n");
}