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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (edgeCount < vertexCount - 1 || vertexCount + vertexCount - 3 < edgeCount) {
        cout << -1;
        return 0;
    }

    for (int sum = 3; sum < edgeCount + 3; sum++) {
        for (int a = 1; 1; a++) {
            int b = sum - a;
            if (a < b && b <= vertexCount) {
                cout << a << " " << b << "\n";
                break;
            }
        }
    }
}