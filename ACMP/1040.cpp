#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    char type;
    string s;
    cin >> type >> s;

    if (type == 'd') {
        cout << "decimal " << s << " is binary ";
        for (int value = stoi(s); value; value /= 2)
            cout << value % 2;
        cout << "0";
    } else {
        cout << "binary " << s << " is decimal ";
        reverse(s.begin(), s.end());
        int value = 0;
        for (char c : s)
            value = value * 2 + c - '0';
        cout << value;
    }
}