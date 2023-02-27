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

    int size, maxJump, forbiddenCount;
    cin >> size >> maxJump >> forbiddenCount;

    vector<int> forbidden(size);
    for (int i = 0; i < forbiddenCount; i++) {
        int index;
        cin >> index;
        forbidden[index - 1] = 1;
    }

    vector<int> ways(size);
    ways[0] = 1;

    for (int i = 1; i < size; i++)
        if (!forbidden[i])
            for (int jump = 1; jump <= maxJump && jump <= i; jump++)
                ways[i] += ways[i - jump];

    cout << ways.back();
}