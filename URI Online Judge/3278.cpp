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

    long long capacity;
    int stationCount;
    cin >> capacity >> stationCount;

    long long size = 0;
    for (int i = 0; i < stationCount; i++) {
        int out, in, stay;
        cin >> out >> in >> stay;

        if (size < out) {
            cout << "impossible\n";
            return 0;
        }

        size -= out;
        size += in;

        if (size > capacity || (size < capacity && stay)) {
            cout << "impossible\n";
            return 0;
        }
    }

    cout << (size ? "impossible\n" : "possible\n");
}