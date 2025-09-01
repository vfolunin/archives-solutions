class Solution {
public:
    bool phonePrefix(vector<string> &a) {
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a.size(); j++)
                if (i != j && a[i].substr(0, a[j].size()) == a[j])
                    return 0;
        return 1;
    }
};