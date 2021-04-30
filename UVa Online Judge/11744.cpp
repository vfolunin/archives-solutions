#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long read() {
    string s;
    cin >> s;

    long long res = 0;
    for (char c : s)
        res = res * 2 + c - '0';

    return res;
}

void print(long long n) {
    for (int bit = 30; bit >= 0; bit--)
        cout << (bool)(n & (1 << bit));
}

const long long MAX = 0x7fffffff;

void solve(int test) {
    long long a = read(), b = read();

    if (test)
        cout << "\n";
    while (1) {
        print(a);
        cout << " ";

        if (b <= MAX)
            print(b);
        else
            cout << "overflow";
        cout << "\n";

        if (b == 0 || b > MAX)
            break;

        long long nextA = a ^ b;
        long long nextB = 2 * (a & b);
        a = nextA;
        b = nextB;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}