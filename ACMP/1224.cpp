#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
	string surname, name;
	vector<int> marks;
	int sum = 0;

	friend istream &operator >> (istream &in, Student &student) {
		in >> student.surname >> student.name;
		in.ignore();
		while (in.peek() != '\n') {
			in >> student.marks.emplace_back();
			student.sum += student.marks.back();
		}
		return in;
	}

	friend ostream &operator << (ostream &out, Student &student) {
		out << student.surname << " " << student.name << " ";
		for (int i = 0; i < student.marks.size(); i++)
			out << (i ? " " : "(") << student.marks[i];
		return out << ")";
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int studentCount, markCount;
	cin >> studentCount >> markCount;

	vector<Student> students(studentCount);
	vector<int> sums(studentCount);
	for (int i = 0; i < studentCount; i++) {
		cin >> students[i];
		sums[i] += students[i].sum;
	}

	sort(sums.rbegin(), sums.rend());

	for (int i = 0; i < students.size(); i++)
		if (students[i].sum >= sums[2])
			cout << students[i] << "\n";
}