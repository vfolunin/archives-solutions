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
    for (int i = a.size() - 1; i >= 0; i--) {
        while (!stack.empty() && a[stack.back()] < a[i]) {
            a[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    for (int i : stack)
        a[i] = -1;

    for (int value : a)
        cout << value << " ";
}