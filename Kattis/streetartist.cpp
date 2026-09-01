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

    vector<pair<string, int>> stack;
    for (int i = 0; i < size; i++) {
        string name;
        int height;
        cin >> name >> height;

        while (!stack.empty() && stack.back().second <= height)
            stack.pop_back();
        stack.push_back({ name, height });
    }

    for (auto &[name, height] : stack)
        cout << name << " ";
}