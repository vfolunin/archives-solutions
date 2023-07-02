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
    size--;

    string surname, name;
    int l, r;
    vector<int> count(size);

    while (cin >> surname >> name >> l >> r) {
        l--;
        r--;
        for (int i = l; i < r; i++)
            count[i]++;
    }

    int maxCount = *max_element(count.begin(), count.end());

    for (int i = 0; i < size; i++)
        if (count[i] == maxCount)
            cout << i + 1 << "-" << i + 2 << "\n";
}