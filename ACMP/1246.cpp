#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct Fraction {
	long long num, den;

	Fraction(long long n = 0, long long d = 1) : num(n), den(d) {
		long long g = gcd(num, den);
		num /= g;
		den /= g;

		if (den < 0) {
			num = -num;
			den = -den;
		}
	}

	Fraction operator + (const Fraction &that) const {
		return { num * that.den + that.num * den, den * that.den };
	}

	Fraction operator - (const Fraction &that) const {
		return { num * that.den - that.num * den, den * that.den };
	}

	Fraction operator * (const Fraction &that) const {
		return { num * that.num, den * that.den };
	}

	Fraction operator / (const Fraction &that) const {
		return { num * that.den, den * that.num };
	}

	friend istream &operator >> (istream &in, Fraction &f) {
		long long num, den = 1;
		in >> num;
		if (in.peek() == '/') {
			in.ignore();
			in >> den;
		}
		f = { num, den };
		return in;
	}

	friend ostream &operator << (ostream &out, const Fraction &f) {
		out << f.num;
		if (f.den != 1)
			out << "/" << f.den;
		return out;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Fraction a, b;
	char op;
	cin >> a >> op >> b;

	if (op == '+')
		cout << a + b;
	else if (op == '-')
		cout << a - b;
	else if (op == '*')
		cout << a * b;
	else if (op == '/')
		cout << a / b;
}