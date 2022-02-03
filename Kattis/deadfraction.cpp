#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

pair<long long, long long> getFrac(string s, string r) {
    long long num = stoll(s + r) - (s.empty() ? 0 : stoll(s));
    long long den = round(pow(10, s.size() + r.size())) - round(pow(10, s.size()));

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    return { num, den };
}

bool solve() {
    char buf[20];
    if (scanf(" 0.%[0-9]...", buf) != 1)
        return 0;

    string s, r = buf;

    long long resNum, resDen = 0;
    while (!r.empty()) {
        auto [num, den] = getFrac(s, r);

        if (!resDen || resDen > den) {
            resNum = num;
            resDen = den;
        }

        s += r[0];
        r = r.substr(1);
    }

    printf("%lld/%lld\n", resNum, resDen);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}