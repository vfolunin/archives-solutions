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

    vector<int> positive, negative, zero;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 0)
            positive.push_back(value);
        else if (value < 0)
            negative.push_back(value);
        else
            zero.push_back(value);
    }

    sort(positive.rbegin(), positive.rend());
    sort(negative.begin(), negative.end());

    for (vector<int> a : { positive, negative, zero })
        for (int value : a)
            cout << value << " ";
}