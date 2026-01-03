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

    vector<int> count = { 1, 1, 2, 2, 2, 8 };
    for (int count : count) {
        int available;
        cin >> available;
        cout << count - available << " ";
    }
}