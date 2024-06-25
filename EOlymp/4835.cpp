#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, vector<int> &a) {
    if (a.size() == size) {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
        return;
    }

    a.push_back(0);
    rec(size, a);
    a.pop_back();

    if (a.empty() || !a.back()) {
        a.push_back(1);
        rec(size, a);
        a.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a;
    rec(size, a);
}