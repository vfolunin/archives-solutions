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

    vector<int> r(a.size(), -1), stack;
    for (int i = 0; i < a.size(); i++) {
        while (!stack.empty() && a[stack.back()] > a[i]) {
            r[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    for (int value : r)
        cout << value << " ";
}