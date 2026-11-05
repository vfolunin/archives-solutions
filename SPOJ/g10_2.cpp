#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toString(int n) {
    vector<string> ones(10);
    ones[0] = "";
    ones[1] = "one";
    ones[2] = "two";
    ones[3] = "three";
    ones[4] = "four";
    ones[5] = "five";
    ones[6] = "six";
    ones[7] = "seven";
    ones[8] = "eight";
    ones[9] = "nine";

    vector<string> tens(10);
    tens[0] = "";
    tens[1] = "ten";
    tens[2] = "twenty";
    tens[3] = "thirty";
    tens[4] = "forty";
    tens[5] = "fifty";
    tens[6] = "sixty";
    tens[7] = "seventy";
    tens[8] = "eighty";
    tens[9] = "ninety";

    vector<string> elevens(10);
    elevens[0] = "ten";
    elevens[1] = "eleven";
    elevens[2] = "twelve";
    elevens[3] = "thirteen";
    elevens[4] = "fourteen";
    elevens[5] = "fifteen";
    elevens[6] = "sixteen";
    elevens[7] = "seventeen";
    elevens[8] = "eighteen";
    elevens[9] = "nineteen"; 
    
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