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

    int h, w;
    cin >> h >> w;

    vector<string> a(1 + 5 * h);
    for (string &s : a)
        cin >> s;

    vector<int> res(5);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int count = 0;
            while (a[1 + y * 5 + count][1 + x * 5] == '*')
                count++;

            res[count]++;
        }
    }

    for (int value : res)
        cout << value << " ";
}