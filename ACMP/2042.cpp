#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> digitSum(int n) {
    vector<int> res(2);
    for (int i = 0; n; i++, n /= 10)
        res[i % 2] += n % 10;
    return res;
}

bool isGood(int n) {
    vector<int> sum = digitSum(n);
    return sum[0] && sum[1] % sum[0] == 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    int count = 0, minSum = 1e9;
    for (int i = 0; i + 2 < a.size(); i++) {
        if (isGood(a[i]) && isGood(a[i + 1]) && isGood(a[i + 2])) {
            count++;
            minSum = min(minSum, a[i] + a[i + 1] + a[i + 2]);
        }
    }

    cout << count << " " << minSum;
}