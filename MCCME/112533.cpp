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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    cout << "Initial array:" << "\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? ", " : "\n");
    cout << "**********\n";

    for (int i = 1; i <= a[0].size(); i++) {
        cout << "Phase " << i << "\n";

        vector<vector<string>> buckets(10);
        for (string &s : a)
            buckets[s[s.size() - i] - '0'].push_back(s);

        for (int bi = 0; bi < buckets.size(); bi++) {
            cout << "Bucket " << bi << ": ";
            if (buckets[bi].empty()) {
                cout << "empty\n";
            } else {
                for (int bj = 0; bj < buckets[bi].size(); bj++)
                    cout << buckets[bi][bj] << (bj + 1 < buckets[bi].size() ? ", " : "\n");
            }
        }
        cout << "**********\n";

        a.clear();
        for (vector<string> &bucket : buckets)
            a.insert(a.end(), bucket.begin(), bucket.end());
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? ", " : "\n");
}