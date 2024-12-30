class Solution {
public:
    string answerString(string &s, int partCount) {
        if (partCount == 1)
            return s;

        string res = s.substr(0, s.size() - partCount + 1);

        for (int from = 1; from < s.size(); from++) {
            int compareResult = 0;
            for (int i = 0; i < res.size() && from + i < s.size() && compareResult != -1; i++)
                if (!compareResult && s[from + i] != res[i])
                    compareResult = s[from + i] < res[i] ? -1 : 1;

            if (compareResult == 1)
                res = s.substr(from, res.size());
        }

        return res;
    }
};