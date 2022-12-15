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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> res = a;
    for (int mark = 4; mark >= 2; mark--) {
        for (int i = 0; i < size; i++) {
            if (a[i] != mark)
                continue;

            for (int neighborMark = 5; neighborMark > mark; neighborMark--) {
                if (i && a[i - 1] == neighborMark && res[i - 1] == neighborMark ||
                    i + 1 < size && a[i + 1] == neighborMark && res[i + 1] == neighborMark) {
                    res[i] = neighborMark;
                    break;
                }
            }
        }
    }

    for (int value : res)
        cout << value << "\n";
}