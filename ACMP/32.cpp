#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long maximize(long long n);

long long minimize(long long n) {
    if (n < 0)
        return -maximize(-n);

    string s = to_string(n);
    sort(s.begin(), s.end());
    if (s != "0")
        swap(s[0], s[s.find_first_not_of('0')]);
    return stoll(s);
}

long long maximize(long long n) {
    if (n < 0)
        return -minimize(-n);

    string s = to_string(n);
    sort(s.rbegin(), s.rend());
    return stoll(s);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;

    cout << maximize(a) - minimize(b);
}