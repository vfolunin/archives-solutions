#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

struct Fraction {
	long long num, den;

	void normalize() {
		long long d = gcd(num, den);
		num /= d;
		den /= d;
	}

	Fraction(long long num, long long den) : num(num), den(den) {
		normalize();
	}

	bool operator < (const Fraction &that) const {
		return num * that.den < that.num * den;
	}

	Fraction operator - (const Fraction &that) const {
		return Fraction(num * that.den - that.num * den, den * that.den);
	}
};

bool solve(int test) {
	long long num, den;
	if (!(cin >> num >> den))
		return 0;

	Fraction f(num, den), l(0, 1), r(1, 1), prevDiff(0, 1);

	if (test)
		cout << "\n";

	while (l.den <= f.den) {
		while (r < f) {
			l.num++;
			r.num++;
		}
		
		Fraction lDiff = f - l;
		Fraction rDiff = r - f;
		if (lDiff < rDiff) {
			if (l.den == 1 || lDiff < prevDiff) {
				cout << l.num << "/" << l.den << "\n";
				prevDiff = lDiff;
			}
		} else {
			if (r.den == 1 || rDiff < prevDiff) {
				cout << r.num << "/" << r.den << "\n";
				prevDiff = rDiff;
			}
		}

		l.den++;
		r.den++;
	}

	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int i = 0; solve(i); i++);
}