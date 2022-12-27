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

    int legSize;
    cin >> legSize;

    vector<int> shoeSize;
    int size;
    while (cin >> size)
        shoeSize.push_back(size);

    if (shoeSize.empty()) {
        cout << 0;
        return 0;
    }

    sort(shoeSize.begin(), shoeSize.end());

    vector<int> res(shoeSize.size());
    for (int i = 0; i < shoeSize.size(); i++) {
        if (shoeSize[i] >= legSize) {
            res[i] = 1;
            for (int j = 0; j < i; j++)
                if (shoeSize[j] + 3 <= shoeSize[i])
                    res[i] = max(res[i], res[j] + 1);
        }
    }

    cout << *max_element(res.begin(), res.end());
}