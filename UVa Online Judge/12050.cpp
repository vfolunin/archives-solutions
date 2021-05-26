#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<map<int, long long>, map<int, long long>> getCount() {
    map<int, long long> count = { {-1, 1}, {0, 1}, {1, 9}, {2, 9} };
    map<int, long long> count0 = { {-1, 1}, {0, 1}, {1, 10}, {2, 10} };
    for (int len = 3; len < 20; len++) {
        count[len] = count[len - 2] * 10;
        count0[len] = count0[len - 2] * 10;
    }
    return { count, count0 };
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;
    n--;

    auto [count, count0] = getCount();

    int len = 1;
    while (n >= count[len]) {
        n -= count[len];
        len++;
    }

    string palindrome;
    for (int i = 0; i < (len + 1) / 2; i++) {
        int digit = (i ? 0 : 1);
        while (n >= count0[len - i * 2 - 2]) {
            n -= count0[len - i * 2 - 2];
            digit++;
        }
        palindrome += digit + '0';
    }

    string rev = palindrome;
    if (len % 2)
        rev.pop_back();
    reverse(rev.begin(), rev.end());
    palindrome += rev;

    cout << palindrome << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}