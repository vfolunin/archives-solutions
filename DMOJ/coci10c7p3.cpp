#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int noteCount, fretCount;
    cin >> noteCount >> fretCount;

    unordered_map<int, vector<int>> stacks;
    int res = 0;

    for (int i = 0; i < noteCount; i++) {
        int str, fret;
        cin >> str >> fret;

        vector<int> &stack = stacks[str];
        while (!stack.empty() && stack.back() > fret) {
            res++;
            stack.pop_back();
        }

        if (stack.empty() || stack.back() != fret) {
            res++;
            stack.push_back(fret);
        }
    }

    cout << res;
}