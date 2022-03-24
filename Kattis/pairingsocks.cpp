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

    vector<int> stackA(size * 2);
    for (int &value : stackA)
        cin >> value;
    reverse(stackA.begin(), stackA.end());

    vector<int> stackB;
    int res = 0;

    while (!stackA.empty()) {
        while (!stackA.empty() && !stackB.empty() && stackA.back() == stackB.back()) {
            stackA.pop_back();
            stackB.pop_back();
            res++;
        }
        if (!stackA.empty()) {
            stackB.push_back(stackA.back());
            stackA.pop_back();
            res++;
        }
    }

    if (stackB.empty())
        cout << res;
    else
        cout << "impossible";
}