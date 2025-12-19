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

    int sum = 0;
    for (int i = 0; i < 6; i++) {
        int value;
        cin >> value;

        sum += value;
    }

    int add, threshold;
    cin >> add >> threshold;

    cout << (sum >= (threshold - add) * 6 ? "yes" : "no");
}