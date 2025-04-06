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

    vector<pair<int, int>> degrees;
    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> degree;

        degrees.push_back({ degree, v });
    }

    sort(degrees.rbegin(), degrees.rend());

    int bi = 1;
    for (auto &[aDegree, a] : degrees) {
        for (int i = 0; i < aDegree; i++) {
            cout << a + 1 << " " << degrees[bi].second + 1 << "\n";

            degrees[bi].first--;
            bi++;
        }
    }
}