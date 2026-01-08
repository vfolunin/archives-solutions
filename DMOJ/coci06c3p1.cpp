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

    vector<int> hats(9);
    int sum = 0;
    for (int &hat : hats) {
        cin >> hat;
        sum += hat;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - hats[i] - hats[j] == 100) {
                for (int k = 0; k < 9; k++)
                    if (k != i && k != j)
                        cout << hats[k] << "\n";
                return 0;
            }
        }
    }
}