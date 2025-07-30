#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    set<unsigned long long> q = { 2, 4 };
    while (!q.empty()) {
        unsigned long long d = *q.begin();
        q.erase(q.begin());

        if (n % d == 0)
            cout << d << "\n";

        for (unsigned long long nextD : { d * 10 + 2, d * 10 + 4 })
            if (nextD <= n)
                q.insert(nextD);
    }
}