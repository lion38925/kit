class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        
        int i,j,n,s,ma;
        
        n = books.size();
        vector<int>v(n+1,0);
        
        
        i=1;
        
        for(auto itr:books){
            v[i] = v[i-1]+itr[1];
            i++;
        }
        
        for(i=2;i<=n;i++){
            
            s = books[i-1][0];      // getting the current width
            ma = books[i-1][1];     // getting the current height
            v[i] = min(v[i],ma+v[i-1]);     // taking case when this current is in new row
            
             for(j=i-2;j>=0;j--){       // going backwards 
                 
                s+=books[j][0];         // adding widths    
                 
                if(s>shelf_width){
                    break;
                }else{
                    ma = max(books[j][1],ma);   // taking max heights 
                    v[i]=min(v[i],ma+v[j]);     // now getting the min from max plus the rest from v
                }
            }
        }
        

        return v[n];
        
    }
};