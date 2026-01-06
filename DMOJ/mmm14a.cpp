#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimeDivisorCount(int n) {
    vector<int> primeDivisorCount(n + 1);
    for (int i = 2; i < primeDivisorCount.size(); i++)
        if (!primeDivisorCount[i])
            for (long long j = i; j < primeDivisorCount.size(); j += i)
                primeDivisorCount[j]++;
    return primeDivisorCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    vector<int> res = getPrimeDivisorCount(r);
    for (int i = l; i <= r; i++)
        cout << res[i] << "\n";
}