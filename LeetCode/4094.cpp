struct Queue {
    queue<int> values;
    unordered_map<int, queue<int>> index;
    int i = 0;
    map<int, int> order;

    void push(int value) {
        values.push(value);
        index[value].push(i++);
        if (index[value].size() == 1)
            order[index[value].front()] = value;
    }

    void pop() {
        int value = values.front();
        values.pop();

        order.erase(index[value].front());
        index[value].pop();

        if (index[value].size())
            order[index[value].front()] = value;
        else
            index.erase(value);
    }

    bool isOk() {
        int targetCount = 1;
        for (auto &[_, value] : order)
            if (index[value].size() != targetCount++)
                return 0;
        return 1;
    }
};

class Solution {
public:
    int countStaircase(vector<int> &a) {
        int res = 0;
        for (int len = 1, add = 2; len <= a.size(); len += add, add++) {
            Queue q;
            for (int i = 0; i < len; i++)
                q.push(a[i]);
            res += q.isOk();

            for (int i = len; i < a.size(); i++) {
                q.push(a[i]);
                q.pop();
                res += q.isOk();
            }
        }
        return res;
    }
};