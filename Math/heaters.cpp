class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int i,j,ma = INT_MIN,k,t;

        
        sort(heaters.begin(),heaters.end());
        
        for(i=0;i<houses.size();i++){
            

                
                k = lower_bound(heaters.begin(), heaters.end(), houses[i])  
            - heaters.begin(); 
                if(k==0)
                    j = INT_MAX;
                else
                    j=houses[i]-heaters[k-1];
                
                if(k>heaters.size()-1)
                   t = INT_MAX;
                else
                    t = heaters[k]-houses[i];
                
                ma = max(ma,min(j,t));
                
        }
        return ma==INT_MIN?0:ma;
    }
};