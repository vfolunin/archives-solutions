#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(const string &s) {
    int sum = 0;
    for (char c : s)
        sum += c - '0';
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int opCount = 0;
    while (s.size() > 1) {
        opCount++;
        s = to_string(digitSum(s));
    }

    cout << s << " " << opCount;
}