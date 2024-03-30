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

    int size, colorCount;
    cin >> size >> colorCount;

    vector<vector<vector<long long>>> ways(size + 1, vector<vector<long long>>(colorCount, vector<long long>(colorCount)));
    for (int i = 0; i < colorCount; i++)
        ways[1][i][i] = 1;

    for (int len = 2; len <= size; len++)
        for (int l = 0; l < colorCount; l++)
            for (int r = 0; r < colorCount; r++)
                for (int prevR = 0; prevR < colorCount; prevR++)
                    if (r != prevR)
                        ways[len][l][r] += ways[len - 1][l][prevR];

    long long res = 0;
    for (int l = 0; l < colorCount; l++)
        for (int r = 0; r < colorCount; r++)
            if (size == 1 || l != r)
                res += ways[size][l][r];

    cout << (res ? res : -1);
}