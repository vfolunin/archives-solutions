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

    vector<int> count(size + 1);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    int res = 0;
    for (int value = 1; value < count.size(); value++)
        res += count[value] == value;

    cout << (res > 1 ? res : 0);
}