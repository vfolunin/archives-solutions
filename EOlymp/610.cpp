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
    scanf("%d", &vertexCount);

    int edgeCount = 0;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int hasEdge;
            scanf("%d", &hasEdge);

            if (a != b)
                edgeCount += hasEdge;
        }
    }

    printf("%d", edgeCount / 2);
}