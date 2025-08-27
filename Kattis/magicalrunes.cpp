#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long fromBin(string &s) {
    long long res = 0;
    for (int i = s.size() - 1; i >= 0; i--)
        res = res * 2 + s[i] - 'A';
    return res;
}

string toBin(long long n, int size) {
    string res;
    for (int i = 0; i < size; i++, n /= 2)
        res += n % 2 + 'A';
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int delta;
    cin >> s >> delta;

    cout << toBin(fromBin(s) + delta, s.size());
}