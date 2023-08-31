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

    long long time, sum;
    cin >> time >> sum;

    long long res = 0;
    for (long long i = 1; i + time - 1 <= sum; i++)
        res += (sum - i) / (time - 1);

    cout << res;
}