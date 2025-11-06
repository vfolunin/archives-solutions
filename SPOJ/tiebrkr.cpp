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

    vector<int> res;
    for (int i = 0; i < size; i++) {
        int value;
        string type;
        cin >> value >> type;

        if (type == "WIN")
            res.push_back(value);
    }

    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}