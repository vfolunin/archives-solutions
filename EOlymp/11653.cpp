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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> sum = a;
    for (int i = 1; i < sum.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                sum[i] = max(sum[i], sum[j] + a[i]);

    cout << *max_element(sum.begin(), sum.end());
}