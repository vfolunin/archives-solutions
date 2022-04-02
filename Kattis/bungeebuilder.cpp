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

    vector<int> heights(size);
    for (int &height : heights)
        cin >> height;

    vector<int> stack, l(size);
    for (int i = 0; i < size; i++) {
        while (!stack.empty() && stack.back() <= heights[i])
            stack.pop_back();
        stack.push_back(heights[i]);
        l[i] = stack[0];
    }

    stack.clear();
    vector<int> r(size);
    for (int i = size - 1; i >= 0; i--) {
        while (!stack.empty() && stack.back() <= heights[i])
            stack.pop_back();
        stack.push_back(heights[i]);
        r[i] = stack[0];
    }

    int maxDist = 0;
    for (int i = 0; i < size; i++)
        maxDist = max(maxDist, min(l[i], r[i]) - heights[i]);

    cout << maxDist << "\n";
}