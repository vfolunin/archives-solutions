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

    string s;
    cin >> s;

    int num = s.front() - '0', den = s.back() - '0';

    cout << (den && num % den == 0 || num % 7 == 0 ? "True" : "False");
}