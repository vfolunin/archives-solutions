#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    long long num, den;

    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {}

    bool operator < (const Fraction &that) const {
        return { num * that.den < that.num * den };
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        return out << f.num << "/" << f.den;
    }
};

void farrey(int num1, int den1, int num2, int den2, vector<Fraction> &fractions) {
    if (den1 + den2 > 2000)
        return;
    farrey(num1, den1, num1 + num2, den1 + den2, fractions);
    fractions.push_back(Fraction(num1 + num2, den1 + den2));
    farrey(num1 + num2, den1 + den2, num2, den2, fractions);
}

vector<Fraction> prepare() {
    vector<Fraction> fractions;
    farrey(0, 1, 1, 1, fractions);
    return fractions;
}

void solve() {
    int limit;
    cin >> limit;

    static vector<Fraction> fractions = prepare();

    for (int i = 0, first = 1; i < fractions.size(); i++) {
        if (fractions[i].den <= limit) {
            if (first)
                first = 0;
            else
                cout << ", ";
            cout << fractions[i];
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}