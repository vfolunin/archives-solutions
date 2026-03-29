#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    static vector<vector<long long>> memo(21, vector<long long>(21, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = c(n - 1, k) + c(n - 1, k - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int n = 0;
    for (int i = 0; i < size; i++) {
        char c;
        cin >> c;

        n += c == 'N';
    }

    cout << c(size, n) - 1;
}