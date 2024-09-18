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
    cin >> s >> s;

    string res, number;
    for (char c : s) {
        if (isdigit(c)) {
            number += c;
        } else {
            if (res.size() < number.size() || res.size() == number.size() && res < number)
                res = number;
            number.clear();
        }
    }
    if (res.size() < number.size() || res.size() == number.size() && res < number)
        res = number;

    cout << res;
}