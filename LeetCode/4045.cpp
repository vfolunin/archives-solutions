class Solution {
public:
    int countGroups(vector<int> &position, vector<int> &speed, int distance) {
        vector<int> newPosition = { position[0] };
        vector<int> newSpeed = { speed[0] };
        for (int i = 1; i < position.size(); i++) {
            if (newPosition.back() + distance < position[i]) {
                newPosition.push_back(position[i]);
                newSpeed.push_back(speed[i]);
            } else {
                newPosition.back() = position[i];
                newSpeed.back() = speed[i];
            }
        }

        int res = 1;
        for (int i = (int)newPosition.size() - 2; i >= 0; i--) {
            if (newSpeed[i] > newSpeed[i + 1])
                newSpeed[i] = newSpeed[i + 1];
            else
                res++;
        }
        return res;
    }
};