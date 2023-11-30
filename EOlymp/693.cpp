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

    int n;
    long long a, b, c, x;
    cin >> n >> a >> b >> c >> x;

    multiset<int> values;
    vector<int> stack;
    long long res = 0;

    for (int i = 0; i < n; i++) {
        x = (a * x * x + b * x + c) / 100 % (int)1e6;

        if (x % 5 < 2) {
            if (!stack.empty()) {
                values.erase(values.find(stack.back()));
                stack.pop_back();
            }
        } else {
            values.insert(x);
            stack.push_back(x);
        }

        if (!values.empty())
            res += *values.begin();
    }

    cout << res;
}