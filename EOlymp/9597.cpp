#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getArray(vector<int> &sums, int first) {
    vector<int> res = { first }, used(sums.size() + 1);
    used[first - 1] = 1;

    for (int sum : sums) {
        int value = sum - res.back();
        if (value < 1 || value > used.size() || used[value - 1])
            return {};

        res.push_back(value);
        used[value - 1] = 1;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> sums(size - 1);
    for (int &sum : sums)
        cin >> sum;

    for (int first = 1; 1; first++) {
        vector<int> res = getArray(sums, first);
        if (!res.empty()) {
            for (int value : res)
                cout << value << " ";
            break;
        }
    }
}