#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getSum(vector<long long> &p, int count) {
    return p.back() - p[p.size() - count - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    vector<long long> p = { 0 };
    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == '+') {
            int value;
            cin >> value;
            p.push_back(p.empty() ? value : p.back() + value);
        } else if (type == '-') {
            cout << getSum(p, 1) << "\n";
            p.pop_back();
        } else {
            int count;
            cin >> count;
            cout << getSum(p, count) << "\n";
        }
    }
}