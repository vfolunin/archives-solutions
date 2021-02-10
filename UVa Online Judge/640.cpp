#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int res = 0;
    while (n > 9) {
        res += n % 10;
        n /= 10;
    }
    return res + n;
}

int d(int n) {
    return n + digitSum(n);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);

    const int N = 1e6;
    vector<int> marked(N + 100);
    for (int i = 1; i <= N; i++)
        marked[d(i)] = 1;

    for (int i = 1; i <= N; i++)
        if (!marked[i])
            cout << i << "\n";
}