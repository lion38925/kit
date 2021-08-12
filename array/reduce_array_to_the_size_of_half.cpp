class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int>q;
        int i,j=0,t=0,n;
        n = arr.size();
        if(n==0)
            return 0;
        unordered_map<int,int>mp;
        for(auto itr:arr){
            mp[itr]++;
        }
        for(auto k:mp){
            q.push(k.second);
        }
        while(!q.empty()){
            int p;
            p=q.top();
            q.pop();
            t+=p;
            j++;
            if(t>=n/2)
                break;
            
        }
        return j;
    }
};