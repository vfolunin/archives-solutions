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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size, 1e9);
    vector<vector<int>> queries(queryCount, vector<int>(3));

    for (vector<int> &query : queries) {
        cin >> query[0] >> query[1] >> query[2];
        query[0]--;
        query[1]--;

        for (int i = query[0]; i <= query[1]; i++)
            a[i] = min(a[i], query[2]);
    }

    for (vector<int> &query : queries) {
        if (*max_element(a.begin() + query[0], a.begin() + query[1] + 1) != query[2]) {
            cout << "FAIL";
            return 0;
        }   
    }

    cout << "EASY\n";
    for (int value : a)
        cout << value << " ";
}