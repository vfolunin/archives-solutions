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

    int amount;
    cin >> amount;

    vector<int> res;
    for (int nominal : { 150, 30, 15, 5, 1 }) {
        res.push_back(amount / nominal);
        amount %= nominal;
    }
    reverse(res.begin(), res.end());

    for (int value : res)
        cout << value << " ";
}