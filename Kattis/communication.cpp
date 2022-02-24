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

    vector<int> decode(256);
    for (int byte = 0; byte < 256; byte++)
        decode[(byte ^ (byte << 1)) & 255] = byte;

    int codeCount;
    cin >> codeCount;

    for (int i = 0; i < codeCount; i++) {
        int code;
        cin >> code;
        cout << decode[code] << " ";
    }
}