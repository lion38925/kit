class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) 

    // in this we check for slope if this is same return false else true
    {
        float x = (points[2][1]-points[0][1])*(points[1][0]-points[0][0]);
        float y = (points[1][1]-points[0][1])*(points[2][0]-points[0][0]);
        return !(x==y);
    }
};