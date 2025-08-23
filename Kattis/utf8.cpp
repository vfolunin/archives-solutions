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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    vector<int> res(4);
    for (int i = 0; i < a.size(); ) {
        if (a[i].substr(0, 1) == "0") {
            res[0]++;
            i++;
        } else if (a[i].substr(0, 3) == "110" && i + 1 < a.size() && a[i + 1].substr(0, 2) == "10") {
            res[1]++;
            i += 2;
        } else if (a[i].substr(0, 4) == "1110" && i + 2 < a.size() && a[i + 1].substr(0, 2) == "10" && a[i + 2].substr(0, 2) == "10") {
            res[2]++;
            i += 3;
        } else if (a[i].substr(0, 5) == "11110" && i + 3 < a.size() && a[i + 1].substr(0, 2) == "10" && a[i + 2].substr(0, 2) == "10" && a[i + 3].substr(0, 2) == "10") {
            res[3]++;
            i += 4;
        } else {
            cout << "invalid";
            return 0;
        }
    }

    for (int value : res)
        cout << value << "\n";
}