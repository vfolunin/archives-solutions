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

    vector<int> res(2);
    for (int i = 0; i < size; i++) {
        int index, add, sub;
        cin >> index >> add >> sub;

        res[index - 1] += add - sub;
    }

    for (int res : res)
        cout << (res >= 0 ? "LIVE\n" : "DEAD\n");
}