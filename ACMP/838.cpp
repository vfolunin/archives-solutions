#include <iostream>
#include <iomanip>
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

	int res = 0;

	string signs = "=+-\'\"";
	string roundBrackets = "()";
	string otherBrackets = "{}[]<>";

	for (char c; cin >> noskipws >> c; ) {
		if (islower(c))
			res += digitSum(c - 'a' + 1);
		else if (isupper(c))
			res += digitSum(c - 'A' + 1) + 10;
		else if (c == ' ')
			res += 4;
		else if (isdigit(c))
			res += 13 - (c - '0');
		else if (c == '.')
			res += 5;
		else if (c == ';')
			res += 7;
		else if (c == ',')
			res += 2;
		else if (signs.find(c) != -1)
			res += 3;
		else if (roundBrackets.find(c) != -1)
			res += 1;
		else if (otherBrackets.find(c) != -1)
			res += 8;
	}

	cout << res;
}