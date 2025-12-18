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

    vector<int> count(20);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    int add;
    cin >> add;
    count[0] += add * 3;

    for (int value = 0; value + 1 < count.size(); value++) {
        count[value + 1] += count[value] / 2;
        if (count[value] % 2)
            cout << value << " ";
    }
}