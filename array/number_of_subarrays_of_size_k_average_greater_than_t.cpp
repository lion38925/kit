class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i,j,t=0;
        
        for(i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        
        i=0;
        if(k<=arr.size()){
            if(arr[k-1]/k>=threshold)
                t++;
        }
        while(i+k<arr.size()){
            //cout<<i<<"^"<<k<<"\n";
            if((arr[i+k]-arr[i])/k>=threshold)
                t++;
            
            i++;
        }
        return t;
    }
};


/// 2nd Solution this is better
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int s=0,avg=0,c=0;
        for(int i=0;i<k;i++){
            s+= arr[i];
        }
        avg = s/k;
        if(avg>=threshold)
            c++;
        for(int i=k;i<arr.size();i++){
            s+= arr[i];
            s-= arr[i-k];
            avg = s/k;
            if(avg>=threshold)
                c++;
            
        }
        return c;
    }
};-av


