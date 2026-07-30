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

    vector<int> count(10);
    for (int i = 0; i < 6; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    int &maxCount = *max_element(count.begin(), count.end());
    if (maxCount < 4) {
        cout << "Alien";
    } else {
        maxCount -= 4;
        cout << (*max_element(count.begin(), count.end()) == 2 ? "Elephant" : "Bear");
    }
}