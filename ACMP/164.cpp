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

int digitRoot(const string &s) {
    int sum = digitSum(s);
    return sum < 10 ? sum : digitRoot(to_string(sum));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int i = 1; i < s.size(); i++) {
        if (digitRoot(s.substr(0, i)) == digitRoot(s.substr(i))) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}