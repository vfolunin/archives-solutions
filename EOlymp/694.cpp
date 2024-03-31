#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    long long a, b, c, value;
    cin >> queryCount >> a >> b >> c >> value;

    multiset<int> values;
    queue<int> q;
    long long res = 0;

    for (int i = 0; i < queryCount; i++) {
        value = (a * value * value + b * value + c) / 100 % (int)1e6;

        if (value % 5 >= 2) {
            values.insert(value);
            q.push(value);
        } else if (!values.empty()) {
            values.erase(values.find(q.front()));
            q.pop();
        }

        if (!values.empty())
            res += *values.begin();
    }

    cout << res;
}