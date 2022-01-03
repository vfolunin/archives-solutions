#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int hammingDistance(string &a, string &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a;
    int limit;
    cin >> a >> limit;

    vector<int> distances(5);
    for (int &distance : distances) {
        string b;
        cin >> b;
        distance = hammingDistance(a, b);
    }

    int index = min_element(distances.begin(), distances.end()) - distances.begin();

    if (distances[index] <= limit)
        cout << index + 1 << "\n" << distances[index] << "\n";
    else
        cout << "-1\n";
}