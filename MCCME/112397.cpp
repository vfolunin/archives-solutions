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

    vector<int> a;
    int value;
    while (cin >> value)
        a.push_back(value);

    stable_sort(a.begin(), a.end(), [](int lhs, int rhs) {
        return digitSum(lhs) > digitSum(rhs);
    });

    for (int value : a)
        cout << value << "\n";
}