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
 
    int legSize, shoeCount;
    cin >> legSize >> shoeCount;

    if (!shoeCount) {
        cout << 0;
        return 0;
    }

    vector<int> shoeSize(shoeCount);
    for (int &size : shoeSize)
        cin >> size;

    sort(shoeSize.begin(), shoeSize.end());

    vector<int> res(shoeCount);
    for (int i = 0; i < shoeCount; i++) {
        if (shoeSize[i] >= legSize) {
            res[i] = 1;
            for (int j = 0; j < i; j++)
                if (shoeSize[j] + 3 <= shoeSize[i])
                    res[i] = max(res[i], res[j] + 1);
        }
    }

    cout << *max_element(res.begin(), res.end());
}