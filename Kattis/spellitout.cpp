#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toString(int n) {
    vector<string> ones = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    vector<string> tens = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    vector<string> elevens = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    string res;

    if (!n) {
        res = "zero";
    } else if (n / 10 == 1) {
        res = elevens[n % 10];
    } else {
        if (n / 10)
            res += tens[n / 10];

        if (!res.empty() && !ones[n % 10].empty())
            res += "-";
        res += ones[n % 10];
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << toString(n);
}