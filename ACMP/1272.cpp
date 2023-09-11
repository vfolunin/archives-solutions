#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string spellShort(int n) {
	static vector<vector<string>> name = {
		{ "", "сто", "двести", "триста", "четыреста", "п€тьсот", "шестьсот", "семьсот", "восемьсот", "дев€тьсот" },
		{ "дес€ть", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "п€тнадцать", "шестнадцать", "семнадцать", "восемнадцать", "дев€тнадцать" },
		{ "", "", "двадцать", "тридцать", "сорок", "п€тьдес€т", "шестьдес€т", "семьдес€т", "восемьдес€т", "дев€носто" },
		{ "", "один", "два", "три", "четыре", "п€ть", "шесть", "семь", "восемь", "дев€ть" }
	};

	string res = name[0][n / 100];

	if (!res.empty() && n % 100)
		res += " ";

	if (10 <= n % 100 && n % 100 < 20) {
		res += name[1][n % 10];
	} else {
		res += name[2][n / 10 % 10];

		if (!res.empty() && res.back() != ' ' && n % 10)
			res += " ";

		res += name[3][n % 10];
	}

	return res;
}

string spellThousands(int n) {
	if (n == 1)
		return "тыс€ча";

	string res = spellShort(n);

	if (n % 10 == 0 || n % 10 >= 5 || n % 100 / 10 == 1)
		return res + " тыс€ч";
	else if (n % 10 >= 3)
		return res + " тыс€чи";
	else if (n % 10 == 2)
		return res.substr(0, res.size() - 1) + "е тыс€чи";
	else
		return res.substr(0, res.size() - 2) + "на тыс€ча";
}

string spell(int n) {
	if (n == 0)
		return "ноль";

	if (n == 1e6)
		return "миллион";

	string res;

	if (n / 1000)
		res += spellThousands(n / 1000);

	if (!res.empty() && n % 1000)
		res += " ";

	res += spellShort(n % 1000);

	return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

	string s = spell(n);

	cout << s.size() - count(s.begin(), s.end(), ' ');
}