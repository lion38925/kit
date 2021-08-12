class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        vector<vector<int>> v(8,vector<int>(8,0));
        vector<vector<int>> vi;
        int i,j,k,l;
        
        
        for(i=0;i<queens.size();i++){
                v[queens[i][0]][queens[i][1]]=1;
        }
        v[king[0]][king[1]]=-1;
        
        qa(v,vi,king);
        return vi;
        
        
    }
   
    void qa(vector<vector<int>>& v, vector<vector<int>>& vi,vector<int>& king){
        int i,j,k,l,m,n;
        i=king[0]+1;
        j=king[1]+1;
        while(i<8&&j<8){
                if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    break;
                }
            i++;
            j++;
        }
            
        i = king[0];
        j = king[1]+1;
            while(j<8){
                if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    //temp.clear();
                    break;
                }     
            j++;
            }
        
        i=king[0]-1;
        j=king[1]+1;
        while(i>=0&&j<8){
                if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    //temp.clear();
                    break;
                }
            i--;
            j++;
        }
        
        j=king[1];
        i=king[0]-1;
        while(i>=0){
                if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    //temp.clear();
                    break;
                }
            i--;
                    
        }
        i=king[0]-1;
        j=king[1]-1;
        while(i>=0&&j>=0){
                if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    //temp.clear();
                    break;
                }
                
            i--;
            j--;
        }
        i=king[0];
        j=king[1]-1;
        while(j>=0){
                if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    //temp.clear();
                    break;
                }
                    
            j--;
        }
        i=king[0]+1;
        j=king[1]-1;
        while(i<8&&j>=0){
            if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    //temp.clear();
                     break;
                }
            i++;
            j--;
            
        }
        i=king[0]+1;
        j=king[1];
        while(i<8){
            if(v[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    vi.push_back(temp);
                    //temp.clear();
                    break;
                }
            i++;
            
        }
        
        
    }
};