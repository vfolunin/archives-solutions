#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum;
    cin >> sum;

    vector<int> res;
    for (int i = max(0, sum - 100); i <= sum; i++)
        if (i + digitSum(i) == sum)
            res.push_back(i);

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << "\n";
}