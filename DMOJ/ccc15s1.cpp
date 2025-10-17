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

    vector<int> stack;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value) {
            stack.push_back(value);
            sum += value;
        } else {
            sum -= stack.back();
            stack.pop_back();
        }
    }

    cout << sum;
}