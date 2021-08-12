class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int i,s=0;
        
        for(i=0;i<points.size()-1;i++){
            
            s+=max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1]));
        }
        return s;
        
    }
};