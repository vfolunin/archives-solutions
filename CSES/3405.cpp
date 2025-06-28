#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct QueueWithOr {
    vector<int> l, r, lOr = { 0 }, rOr = { 0 };

    void move() {
        while (!r.empty()) {
            l.push_back(r.back());
            lOr.push_back(lOr.back() | l.back());
            r.pop_back();
            rOr.pop_back();
        }
    }

    void push(int value) {
        r.push_back(value);
        rOr.push_back(rOr.back() | r.back());
    }

    void pop() {
        if (l.empty())
            move();
        l.pop_back();
        lOr.pop_back();
    }

    int getOr() {
        return lOr.back() | rOr.back();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, windowSize;
    cin >> size >> windowSize;

    vector<int> a(size);
    long long b, c;
    int mod;
    cin >> a[0] >> b >> c >> mod;

    for (int i = 1; i < size; i++)
        a[i] = (a[i - 1] * b + c) % mod;

    QueueWithOr q;
    for (int i = 0; i < windowSize; i++)
        q.push(a[i]);

    int res = q.getOr();
    for (int i = windowSize; i < size; i++) {
        q.push(a[i]);
        q.pop();
        res ^= q.getOr();
    }

    cout << res;
}