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

    int price, size;
    cin >> price >> size;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
    }
    sum -= price;

    vector<int> res;
    for (int nominal : { 500, 100, 50, 10, 5, 2, 1 }) {
        while (sum >= nominal) {
            sum -= nominal;
            res.push_back(nominal);
        }
    }

    for (int value : res)
        cout << value << " ";
}