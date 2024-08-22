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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end(), [](int lhs, int rhs) {
        int lSum = digitSum(lhs), rSum = digitSum(rhs);
        if (lSum != rSum)
            return lSum < rSum;
        return lhs > rhs;
    });

    for (int value : a)
        cout << value << " ";
}