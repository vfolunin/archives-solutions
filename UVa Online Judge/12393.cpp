#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> prefixSum(n);
    for (int &x : prefixSum)
        cin >> x;

    prefixSum.insert(prefixSum.end(), prefixSum.begin(), prefixSum.end());
    for (int i = 1; i < prefixSum.size(); i++)
        prefixSum[i] += prefixSum[i - 1];

    deque<int> q;
    int res = 0;

    for (int i = 0; i < prefixSum.size(); i++) {
        while (!q.empty() && q.front() + n < i)
            q.pop_front();

        while (!q.empty() && prefixSum[q.back()] >= prefixSum[i])
            q.pop_back();

        q.push_back(i);

        if (n <= i && prefixSum[q.front()] >= prefixSum[i - n])
            res++;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}