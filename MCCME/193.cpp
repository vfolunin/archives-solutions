#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<vector<vector<long long>>, vector<long long>> prepare() {
    vector<vector<long long>> count(100, vector<long long>(10));

    for (int first = 1; first < count[0].size(); first++)
        count[0][first] = count[1][first] = 1;

    for (int size = 2; size < count.size(); size++)
        for (int first = 1; first < count[0].size(); first++)
            for (int second = first; second < count[0].size(); second++)
                count[size][first] += count[size - 1][second];

    vector<long long> totalCount(count.size());
    for (int size = 1; size < count.size(); size++)
        for (int first = 1; first < count[0].size(); first++)
            totalCount[size] += count[size][first];

    return { count, totalCount };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int index;
    cin >> index;
    index--;

    static auto [count, totalCount] = prepare();

    int size = 1;
    while (index >= totalCount[size]) {
        index -= totalCount[size];
        size++;
    }

    string res;
    for (int i = 0; i < size; i++) {
        int digit = res.empty() ? 1 : res.back() - '0';
        while (index >= count[size - i][digit]) {
            index -= count[size - i][digit];
            digit++;
        }
        res += '0' + digit;
    }

    cout << res;
}