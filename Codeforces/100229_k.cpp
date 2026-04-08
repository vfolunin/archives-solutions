#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
  
    int size;
    cin >> size;
    size += 2;

    vector<int> a(size);
    for (int i = 1; i + 1 < a.size(); i++)
        cin >> a[i];

    int maxJump;
    cin >> maxJump;

    vector<int> maxSum(a.size(), -1e9);
    maxSum[0] = 0;

    for (int i = 1; i < maxSum.size(); i++)
        for (int jump = 1; jump <= maxJump && jump <= i; jump++)
            maxSum[i] = max(maxSum[i], maxSum[i - jump] + a[i]);

    cout << maxSum.back();
}