#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool better(vector<int> &a, vector<int> &b) {
    int num = 0, den = 0;
    for (int aValue : a) {
        for (int bValue : b) {
            num += aValue > bValue;
            den += aValue != bValue;
        }
    }
    return den && num * 2 >= den;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> dice(3, vector<int>(6));
    for (vector<int> &die : dice)
        for (int &value : die)
            cin >> value;

    for (int i = 0; i < dice.size(); i++) {
        int ok = 1;
        for (int j = 0; j < dice.size(); j++)
            ok &= i == j || better(dice[i], dice[j]);

        if (ok) {
            cout << i + 1;
            return 0;
        }
    }

    cout << "No dice";
}