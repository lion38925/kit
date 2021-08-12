class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        int i,j,l;
        vector<int>v;
        
        
        queue<string>q;
        
        for(i=1;i<10;i++){
            q.push(to_string(i));
        }
        
        while(!q.empty()){
            
            string kit,s;
            kit = q.front();
            q.pop();
            if(kit.length()==n)
                v.push_back(stoi(kit));
            else{
                l = kit[kit.length()-1]-'0';
                for(i=0;i<10;i++){
                    if(abs(i-l)==k){
                        s = kit;
                        s.push_back(i+'0');
                        q.push(s);
                    }
                }
            }
            
            
        }
        return v;
        
    }
};