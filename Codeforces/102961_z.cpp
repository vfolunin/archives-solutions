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
    for (int &x : a)
        cin >> x;

    vector<int> res(size), stack;
    for (int i = size - 1; i >= 0; i--) {
        while (!stack.empty() && a[i] < a[stack.back()]) {
            res[stack.back()] = i + 1;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    for (int x : res)
        cout << x << " ";
}