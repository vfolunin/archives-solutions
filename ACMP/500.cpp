#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Person {
	int age, risk;

	bool operator < (const Person &that) const {
		return age < that.age;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int personCount;
	cin >> personCount;
	
	vector<Person> persons(personCount);
	for (auto &[age, risk] : persons)
		cin >> age >> risk;

	sort(persons.begin(), persons.end());

	vector<int> totalRisk = { persons[0].risk, persons[1].risk };
	if (personCount > 2) {
		totalRisk.push_back(persons[1].risk + persons[2].risk);
		for (int i = 3; i < personCount; i++)
			totalRisk.push_back(persons[i].risk + min(totalRisk[i - 1], totalRisk[i - 2]));
	}

	cout << totalRisk[personCount - 1];
}