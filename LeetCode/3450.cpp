class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>> &students) {
        unordered_map<int, unordered_set<int>> bench;
        for (vector<int> &student : students)
            bench[student[1]].insert(student[0]);
        
        int res = 0;
        for (auto &[_, students] : bench)
            res = max<int>(res, students.size());
        return res;
    }
};