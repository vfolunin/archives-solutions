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

    vector<int> stack;
    int carIndex = 1;

    for (int value : a) {
        stack.push_back(value);
        while (!stack.empty() && stack.back() == carIndex) {
            stack.pop_back();
            carIndex++;
        }
    }

    cout << (stack.empty() ? "YES" : "NO");
}