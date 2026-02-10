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
 
    long long size, extraCount, limit;
    cin >> size >> extraCount >> limit;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int res = 1;
    vector<long long> gaps;
    for (int i = 1; i < size; i++) {
        if (a[i] - a[i - 1] > limit) {
            res++;
            gaps.push_back((a[i] - a[i - 1] - 1) / limit);
        }
    }

    sort(gaps.begin(), gaps.end());

    for (long long gap : gaps) {
        if (extraCount >= gap) {
            extraCount -= gap;
            res--;
        }
    }

    cout << res;
}