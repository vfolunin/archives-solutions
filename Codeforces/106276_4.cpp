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

    int size;
    cin >> size;

    vector<int> limit(size);
    for (int &value : limit)
        cin >> value;

    vector<int> sumLimit(size);
    for (int &value : sumLimit)
        cin >> value;

    vector<pair<int, int>> stack;
    long long sum = 0;

    for (int i = limit.size() - 1; i >= 0; i--) {
        stack.push_back({ i, limit[i] });
        sum += limit[i];

        while (sum > sumLimit[i]) {
            int delta = min<long long>(sum - sumLimit[i], stack.back().second);
            sum -= delta;
            stack.back().second -= delta;
            if (!stack.back().second)
                stack.pop_back();
        }
    }

    vector<int> res(limit.size());
    for (auto &[i, value] : stack)
        res[i] = value;

    for (int value : res)
        cout << value << "\n";
}