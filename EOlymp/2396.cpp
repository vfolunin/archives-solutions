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

    if (n >= 100) {
        res += ones[n / 100] + " hundred";
        n %= 100;
    }

    if (n / 10 == 1) {
        if (!res.empty())
            res += " ";
        res += elevens[n % 10];
    } else {
        if (n / 10) {
            if (!res.empty())
                res += " ";
            res += tens[n / 10];
        }

        if (!res.empty())
            res += " ";
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