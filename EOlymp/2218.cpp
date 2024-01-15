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

    vector<int> count(2);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    cout << min(count[0], count[1]);
}