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
        return num * that.den < that.num * den;
    }

    Fraction(long long num = 0, long long den = 1) : num(num), den(den) {}

    Fraction operator - (const Fraction &that) const {
        return Fraction(num * that.den - that.num * den, den * that.den);
    }

    Fraction operator * (const Fraction &that) const {
        return Fraction(num * that.num, den * that.den);
    }

    Fraction operator / (const Fraction &that) const {
        return Fraction(num * that.den, den * that.num);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int numCount, denCount, percent;
    cin >> numCount >> denCount >> percent;

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

    for (int i = 0; i + 1 < fractions.size(); i++) {
        if (fractions[i] * percent / 100 < fractions[i + 1] - fractions[i]) {
            cout << "Time to change gears!";
            return 0;
        }
    }

    cout << "Ride on!";
}