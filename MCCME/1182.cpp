#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<int> &itemWeight, int i, int balance, vector<int> &left, vector<int> &right) {
    if (i == itemWeight.size()) {
        if (!balance) {
            if (left.empty()) {
                cout << 0;
            } else {
                for (int value : left)
                    cout << value << " ";
            }
            cout << "\n";

            if (right.empty()) {
                cout << 0;
            } else {
                for (int value : right)
                    cout << value << " ";
            }
            exit(0);
        }

        return;
    }

    rec(itemWeight, i + 1, balance, left, right);

    left.push_back(itemWeight[i]);
    rec(itemWeight, i + 1, balance - itemWeight[i], left, right);
    left.pop_back();

    right.push_back(itemWeight[i]);
    rec(itemWeight, i + 1, balance + itemWeight[i], left, right);
    right.pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetWeight, itemCount;
    cin >> targetWeight >> itemCount;

    vector<int> itemWeight(itemCount);
    for (int &weight : itemWeight)
        cin >> weight;

    vector<int> left, right;
    rec(itemWeight, 0, -targetWeight, left, right);

    cout << -1;
}