#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Pair {
    long long a, b;

    Pair(long long a, long long b) : a(a), b(b) {}

    bool operator < (const Pair &that) const {
        return a + b < that.a + that.b;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;
    queryCount -= size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    multiset<Pair> pairs;
    for (int i = 0; i + 1 < a.size(); i++)
        pairs.insert(Pair(a[i], a[i + 1]));

    for (int i = 0; i < queryCount; i++) {
        Pair pair = *pairs.begin();
        a.push_back(pair.a + pair.b);
        pairs.erase(pairs.begin());
        pairs.insert(Pair(pair.a, pair.a + pair.b));
        pairs.insert(Pair(pair.a + pair.b, pair.b));
    }

    cout << *max_element(a.begin(), a.end());
}