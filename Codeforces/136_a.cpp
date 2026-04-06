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

    vector<int> res(size);
    for (int value = 0; value < size; value++) {
        int index;
        cin >> index;

        res[index - 1] = value;
    }

    for (int value : res)
        cout << value + 1 << " ";
}