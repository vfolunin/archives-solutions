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

    int size, remainingSize;
    cin >> size >> remainingSize;

    set<int> missing;
    for (int num = 1; num <= size; num++)
        missing.insert(num);

    vector<int> remainingP(remainingSize);
    for (int &num : remainingP) {
        cin >> num;
        missing.erase(num);
    }

    for (int num : remainingP) {
        while (!missing.empty() && *missing.begin() < num) {
            cout << *missing.begin() << "\n";
            missing.erase(missing.begin());
        }
        cout << num << "\n";
    }

    while (!missing.empty()) {
        cout << *missing.begin() << "\n";
        missing.erase(missing.begin());
    }
}