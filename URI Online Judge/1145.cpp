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

    int width, limit;
    cin >> width >> limit;

    for (int i = 1; i <= limit; )
        for (int j = 0; j < width; i++, j++)
            cout << i << (j + 1 < width ? " " : "\n");
}