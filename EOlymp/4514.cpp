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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> stack, res;
    int carIndex = 1;

    for (int value : a) {
        stack.push_back(value);
        res.push_back(1);

        while (!stack.empty() && stack.back() == carIndex) {
            res.push_back(2);
            stack.pop_back();
            carIndex++;
        }
    }

    if (stack.empty()) {
        for (int value : res)
            cout << value << " 1\n";
    } else {
        cout << 0;
    }
}