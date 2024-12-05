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

    int res = 0;
    string resName;

    for (int i = 0; i < size; i++) {
        string name;
        int a, b;
        cin >> name >> a >> b;

        if (res < (a + 1) * b) {
            res = (a + 1) * b;
            resName = name;
        }
    }

    cout << resName << " " << res;
}