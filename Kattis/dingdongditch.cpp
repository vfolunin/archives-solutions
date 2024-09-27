#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;

    sort(p.begin(), p.end());
    partial_sum(p.begin(), p.end(), p.begin());

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;

        cout << p[index - 1] << "\n";
    }
}