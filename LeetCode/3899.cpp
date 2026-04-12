class Solution {
    double getAngle(double a, double b, double c) {
        return acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / acos(-1);
    }
    
public:
    vector<double> internalAngles(vector<int> &sides) {
        sort(sides.begin(), sides.end());
        if (sides[0] + sides[1] <= sides[2])
            return {};
        
        vector<double> angles;
        for (int i = 0; i < sides.size(); i++)
            angles.push_back(getAngle(sides[i], sides[(i + 1) % sides.size()], sides[(i + 2) % sides.size()]));
        sort(angles.begin(), angles.end());
        return angles;
    }
};