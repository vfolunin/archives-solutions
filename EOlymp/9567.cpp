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

    for (int y = 0; y < h; y++) {
        int zeroCount = 0;

        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            if (value)
                cout << value << " ";
            else
                zeroCount++;
        }

        for (int x = 0; x < zeroCount; x++)
            cout << "0 ";
        
        cout << "\n";
    }
}