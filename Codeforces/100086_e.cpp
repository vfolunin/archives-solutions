#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int from, int size, vector<int> &combination) {
    if (combination.size() == size) {
        for (int value : combination)
            cout << value << " ";
        cout << "\n";
    }

    for (int value = from; value; value--) {
        combination.push_back(value);
        rec(value - 1, size, combination);
        combination.pop_back();
    }
}

int main() {
    freopen("generation.in", "r", stdin);
    freopen("generation.out", "w", stdout);

    int from, size;
    cin >> from >> size;

    vector<int> combination;
    rec(from, size, combination);
}