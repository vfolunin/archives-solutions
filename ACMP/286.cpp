#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Decimal {
	string sign = "+", whole, frac;

	bool operator < (const Decimal &that) const {
		if (sign != that.sign)
			return sign == "-";
		if (whole.size() != that.whole.size())
			return sign == "+" ? whole.size() < that.whole.size() : whole.size() > that.whole.size();
		if (whole != that.whole)
			return sign == "+" ? whole < that.whole : whole > that.whole;
		return sign == "+" ? frac < that.frac : frac > that.frac;
	}

	friend istream &operator >> (istream &in, Decimal &d) {
		in >> d.whole;
		if (d.whole[0] == '-') {
			d.sign = "-";
			d.whole = d.whole.substr(1);
		}
		if (int dot = d.whole.find('.'); dot != -1) {
			d.frac = d.whole.substr(dot + 1);
			d.whole = d.whole.substr(0, dot);
		}
		while (d.frac.size() && d.frac.back() == '0')
			d.frac.pop_back();
		return in;
	}
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	Decimal a, b;
	cin >> a >> b;

	if (a < b)
		cout << "<";
	else if (b < a)
		cout << ">";
	else
		cout << "=";
}