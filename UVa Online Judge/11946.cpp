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

    int n;
    cin >> n;
    cin.ignore();

    char c;
    cin >> noskipws;
    while (cin >> c) {
        static string code = "OIZEASGTBP";
        if (isdigit(c))
            cout << code[c - '0'];
        else
            cout << c;
    }
}