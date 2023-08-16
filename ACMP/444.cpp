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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector<string> res(a.size());
    res[0] = to_string(a[0]);

    for (int i = 1; i < a.size(); i++) {
        res[i] = res[i - 1] + ", " + to_string(a[i]);
        
        int j = i;
        while (j && a[i] - a[j - 1] == i - j + 1)
            j--;
        string candidate = res[j] + ", ..., " + to_string(a[i]);

        if (res[i].size() > candidate.size())
            res[i] = candidate;
    }

    cout << res.back();
}