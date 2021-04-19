#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const string digits = "0123456789ABCDEF";

void processArg(string &hex, int &index) {
	int bits = digits.find(hex[index++]) << 12;
	bits += digits.find(hex[index++]) << 8;
	bits += digits.find(hex[index++]) << 4;
	bits += digits.find(hex[index++]);

	int mode = bits >> 14;
	int arg = bits & ((1 << 14) - 1);

	if (mode == 0)
		cout << "R" << arg;
	else if (mode == 1)
		cout << "$" << arg;
	else if (mode == 2)
		cout << "PC+" << arg;
	else
		cout << arg;
}

void processOp(string &hex, int &index) {
	static vector<string> op = {
		"ADD", "SUB", "MUL", "DIV", "MOV", "BREQ", "BRLE", "BRLS",
		"BRGE", "BRGR", "BRNE", "BR", "AND", "OR", "XOR", "NOT"
	};
	static vector<int> argCount = {
		2, 2, 2, 2, 2, 1, 1, 1,
		1, 1, 1, 1, 3, 3, 3, 1
	};

	int d = digits.find(hex[index++]);
	cout << op[d] << " ";
	for (int i = 0; i < argCount[d]; i++) {
		processArg(hex, index);
		cout << (i + 1 < argCount[d] ? "," : "\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string hex;
	char c;
	while (cin >> c)
		hex += c;

	int index = 0;
	while (index < hex.size())
		processOp(hex, index);
}