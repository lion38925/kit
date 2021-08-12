class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size()<3)
            return true;
        
        int i,dx,dy;
        dy=coordinates[1][1]-coordinates[0][1];
        dx=coordinates[1][0]-coordinates[0][0];
        // take initial slope of first two points
        
        for(i=2;i<coordinates.size();i++){
            // now check slope with point and initial point 0 
            if(dx*(coordinates[i][1]-coordinates[0][1])!=dy*(coordinates[i][0]-coordinates[0][0]))
                return false;
        }
            
        
        return true;
    }
};