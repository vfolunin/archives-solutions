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

    vector<int> a = {
        100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000
    };
    int num = accumulate(a.begin(), a.end(), 0), den = a.size();

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;

        num -= a[index - 1];
        den--;
    }

    int proposal;
    cin >> proposal;

    cout << (num < proposal * den ? "deal" : "no deal");
}