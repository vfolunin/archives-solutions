#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int num = 0, den = n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num += x;
    }

    int g = gcd(num, den);
    num /= g;
    den /= g;

    if (den < 0) {
        num = -num;
        den = -den;
    }

    cout << "Case " << test << ":\n";
    if (num % den == 0) {
        if (num < 0)
            cout << "- ";
        cout << abs(num / den) << "\n";
    } else {
        string s[3];
        
        if (num < 0)
            s[1] += "- ";
        if (num / den)
            s[1] += to_string(abs(num / den));
        s[0] = s[2] = string(s[1].size(), ' ');

        num = abs(num) % den;
        string sNum = to_string(num);
        string sDen = to_string(den);
        sNum = string(max(sNum.size(), sDen.size()) - sNum.size(), ' ') + sNum;
        sDen = string(max(sNum.size(), sDen.size()) - sDen.size(), ' ') + sDen;
        s[0] += sNum;
        s[1] += string(sNum.size(), '-');
        s[2] += sDen;

        cout << s[0] << "\n";
        cout << s[1] << "\n";
        cout << s[2] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}