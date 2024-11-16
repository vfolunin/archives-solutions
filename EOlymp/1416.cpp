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

    int size;
    cin >> size;

    vector<long long> ways = {
        1, 4, 12, 36, 100,
        284, 780, 2172, 5916, 16268,
        44100, 120292, 324932, 881500, 2374444,
        6416596, 17245332, 46466676, 124658732, 335116620,
        897697164, 2408806028, 6444560484
    };

    cout << ways[size];
}