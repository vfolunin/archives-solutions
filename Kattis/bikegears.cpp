#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    long long num, den;

    bool operator < (const Fraction &that) const {
        return num * that.den < that.num * den ||
               num * that.den == that.num * den && num < that.num;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int numCount, denCount;
    cin >> numCount >> denCount;

    vector<int> nums(numCount);
    for (int &num : nums)
        cin >> num;

    vector<int> dens(denCount);
    for (int &den : dens)
        cin >> den;

    vector<Fraction> fractions;
    for (int num : nums)
        for (int den : dens)
            fractions.push_back({ num, den });
    sort(fractions.begin(), fractions.end());

    for (auto &[num, den] : fractions)
        cout << "(" << num << "," << den << ")\n";
}