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

    vector<int> count(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[((i - value + 1) % size + size) % size]++;
    }

    auto it = max_element(count.begin(), count.end());

    cout << it - count.begin() << " " << *it;
}