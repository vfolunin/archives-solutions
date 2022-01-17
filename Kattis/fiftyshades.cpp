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

    int colorCount;
    cin >> colorCount;

    int res = 0;

    for (int i = 0; i < colorCount; i++) {
        string color;
        cin >> color;

        for (char &c : color)
            c = tolower(c);

        if (color.find("pink") != -1 || color.find("rose") != -1)
            res++;
    }

    if (res)
        cout << res;
    else
        cout << "I must watch Star Wars with my daughter";
}