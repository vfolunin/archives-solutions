#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int N = 1e5;

int digitSquareSum(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

int getIterCount(int n) {
    static vector<int> iterCount(N);
    if (iterCount[n])
        return iterCount[n];

    if (n == 1)
        return iterCount[n] = 1;
    
    iterCount[n] = -2;

    int sum = digitSquareSum(n);
    if (getIterCount(sum) < 0)
        iterCount[n] = -1;
    else
        iterCount[n] = getIterCount(sum) + 1;

    return iterCount[n];
}

pair<vector<int>, vector<int>> prepare() {
    vector<int> happy, iterCount;
    for (int i = 1; i < N; i++) {
        if (getIterCount(i) >= 0) {
            happy.push_back(i);
            iterCount.push_back(getIterCount(i));
        }
    }
    return { happy, iterCount };
}

bool solve(int test) {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    static auto [happy, iterCount] = prepare();

    int li = lower_bound(happy.begin(), happy.end(), l) - happy.begin();
    int ri = upper_bound(happy.begin(), happy.end(), r) - happy.begin();

    if (test)
        cout << "\n";
    for (int i = li; i < ri; i++)
        cout << happy[i] << " " << iterCount[i] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}