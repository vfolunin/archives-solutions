class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        vector<int> studentCount(2);
        for (int student : students)
            studentCount[student]++;
            
        for (int sandwich : sandwiches) {
            if (studentCount[sandwich])
                studentCount[sandwich]--;
            else
                return studentCount[0] + studentCount[1];
        }
        
        return 0;
    }
};