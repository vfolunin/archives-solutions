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

    int size, add;
    cin >> size >> add;

    vector<int> count(7);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    cout << (*max_element(count.begin(), count.end()) + add >= size ? "Ja" : "Nej");
}