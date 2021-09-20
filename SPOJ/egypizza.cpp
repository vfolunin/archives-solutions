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

    int requestCount;
    cin >> requestCount;

    map<string, int> requests;
    for (int i = 0; i < requestCount; i++) {
        string request;
        cin >> request;
        requests[request]++;
    }

    int res = 1;
    res += requests["3/4"];
    requests["1/4"] = max(0, requests["1/4"] - requests["3/4"]);
    res += (requests["1/2"] + 1) / 2;
    if (requests["1/2"] % 2)
        requests["1/4"] = max(0, requests["1/4"] - 2);
    res += (requests["1/4"] + 3) / 4;

    cout << res;
}