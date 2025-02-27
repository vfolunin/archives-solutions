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

    sort(a.rbegin(), a.rend());

    vector<int> sum(2, 1);
    for (int i = 0; i < a.size(); i++)
        sum[i % 2] += a[i];

    cout << sum[0] << "\n" << sum[1];
}