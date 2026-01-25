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

    vector<int> pos(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value - 1] = i;
    }

    vector<int> count(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        int shift = (i - pos[value - 1] + size) % size;
        count[shift]++;
    }

    cout << *max_element(count.begin(), count.end());
}