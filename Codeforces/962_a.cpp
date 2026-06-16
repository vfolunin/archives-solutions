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
    int totalSum = 0;
    for (int &value : a) {
        cin >> value;
        totalSum += value;
    }

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (sum * 2 >= totalSum) {
            cout << i + 1;
            break;
        }
    }
}