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

	vector<int> count(51);
	for (int i = 0; i < a.size(); i++)
		if (a[i] == a[(i + 1) % a.size()])
			count[a[i]]++;

	cout << (*max_element(count.begin(), count.end()) >= 2 ? "Yes" : "No");
}