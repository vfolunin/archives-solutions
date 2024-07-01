#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct Hasher {
    unsigned long long x = 31;
    vector<unsigned long long> p, h;

    Hasher(const string &s) {
        p.resize(s.size());
        h.resize(s.size());

        p[0] = 1;
        h[0] = s[0] - 'a' + 1;

        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * x;
            h[i] = h[i - 1] * x + s[i] - 'a' + 1;
        }
    }

    unsigned long long getHash(int l, int r) {
        unsigned long long res = h[r];
        if (l)
            res = res - p[r - l + 1] * h[l - 1];
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int size = s.size();
    s += s;
    Hasher hasher(s);

    vector<int> order(size);
    iota(order.begin(), order.end(), 0);
    int from = *min_element(order.begin(), order.end(), [&](int a, int b) {
        int l = 0, r = size;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (hasher.getHash(a, a + m - 1) == hasher.getHash(b, b + m - 1))
                l = m;
            else
                r = m;
        }
        return s[a + l] < s[b + l];
    });

    cout << s.substr(from, size);
}