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

    long long sum = 0, res = 0;
    for (long long i = 0; i < a.size(); i++) {
        res += i * a[i] - sum;
        sum += a[i];
    }

    cout << res;
}