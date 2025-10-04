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

    int vertexCount;
    cin >> vertexCount;

    int minDegree = 1e9;
    for (int a = 0; a < vertexCount; a++) {
        int degree = 0;

        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            cin >> hasEdge;

            degree += hasEdge;
        }

        minDegree = min(minDegree, degree);
    }

    cout << minDegree * 2;
}