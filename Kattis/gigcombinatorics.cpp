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

    const long long MOD = 1e9 + 7;

    vector<long long> count1(size);
    for (int i = 0; i < a.size(); i++)
        count1[i] = (i ? count1[i - 1] : 0) + (a[i] == 1);

    vector<long long> count12(size);
    for (int i = 1; i < a.size(); i++) 
        count12[i] = a[i] == 2 ? (count12[i - 1] * 2 + count1[i]) % MOD : count12[i - 1];

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == 3)
            res = (res + count12[i]) % MOD;

    cout << res;
}