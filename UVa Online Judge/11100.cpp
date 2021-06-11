#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<int> arr(size);
    map<int, int> count;
    int maxCount = 0;

    for (int &x : arr) {
        cin >> x;
        maxCount = max(maxCount, ++count[x]);
    }

    for (auto &[_, k] : count)
        for (int i = k; i < maxCount; i++)
            arr.push_back(0);
    sort(arr.begin(), arr.end());

    if (test)
        cout << "\n";
    cout << maxCount << "\n";
    for (int i = 0; i < maxCount; i++)
        for (int j = i; j < arr.size(); j += maxCount)
            if (arr[j])
                cout << arr[j] << (j + maxCount < arr.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}