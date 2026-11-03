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

    vector<string> res = { "16", "06", "68", "88" };
    if (size <= res.size()) {
        for (int i = 0; i < size; i++)
            cout << res[i] << " ";
    } else {
        cout << "Glupenky Pierre";
    }
}