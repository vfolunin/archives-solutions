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

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    vector<long long> sum(2);
    for (int i = 0; i < a.size(); i++)
        sum[i >= a.size() / 2] += a[i];

    cout << sum[0] * sum[0] + sum[1] * sum[1];
}