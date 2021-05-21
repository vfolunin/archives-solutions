#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> parse(string &s, int l, int r, int size) {
    l++;
    r--;
    
    long long n = 0;
    int sign = 1;
    if (s[l] == '-') {
        sign = -1;
        l++;
    }
    while (isdigit(s[l])) {
        n = n * 10 + s[l] - '0';
        l++;
    }
    n *= sign;

    vector<long long> res;

    if (l > r) {
        for (int i = 0; i < size; i++)
            res.push_back(n);
        return res;
    }

    vector<long long> seq = parse(s, l + 1, r, size);
    if (s[l] == '+') {
        res.push_back(n);
        for (int i = 1; i < size; i++)
            res.push_back(res.back() + seq[i - 1]);
    } else {
        res.push_back(n * seq[0]);
        for (int i = 1; i < size; i++)
            res.push_back(res.back() * seq[i]);
    }
    return res;
}

bool solve() {
    string formula;
    int size;
    if (!(cin >> formula >> size))
        return 0;

    vector<long long> seq = parse(formula, 0, formula.size() - 1, size);
    
    for (int i = 0; i < size; i++)
        cout << seq[i] << (i + 1 < seq.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}