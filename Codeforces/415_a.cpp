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

    int lampCount, buttonCount;
    cin >> lampCount >> buttonCount;

    vector<int> buttons(buttonCount);
    for (int &button : buttons)
        cin >> button;

    for (int lamp = 1; lamp <= lampCount; lamp++) {
        int i = 0;
        while (buttons[i] > lamp)
            i++;

        cout << buttons[i] << " ";
    }
}