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

    vector<int> res;
    for (int i = 0; i < size; i++) {
        int value = 1;
        while (!res.empty() && res.back() == value) {
            res.pop_back();
            value++;
        }
        res.push_back(value);
    }

    for (int value : res)
        cout << value << " ";
}