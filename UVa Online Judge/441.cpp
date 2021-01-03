#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    sort(v.begin(), v.end());

    vector<int> mask(n);
    fill(mask.begin(), mask.begin() + 6, 1);
    sort(mask.begin(), mask.end());

    set<vector<int>> answer;
    do {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if (mask[i])
                subset.push_back(v[i]);
        answer.insert(subset);
    } while (next_permutation(mask.begin(), mask.end()));

    if (test)
        cout << "\n";
    for (const vector<int> &subset : answer)
        for (int i = 0; i < 6; i++)
            cout << subset[i] << (i < 5 ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    for (int test = 0; solve(test); test++);
}