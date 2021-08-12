class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.size()==0 || K==0)return 0;
        int i,j,k,l,m,n;
        
        n = A.size();
        
        double s=0;
        vector<vector<double>>v(K+1,vector<double>(n+1,0));
        
        vector<double>S;
        
        for(i=0;i<n;i++){
            v[0][i] = (s+A[i])/(i+1);   // making first row and second one accordingly just adding and dividing
            v[1][i] = (s+A[i])/(i+1);
            s+=A[i];
            S.push_back(s);
        }
        
        for(i=0;i<n;i++){
            
            for(k=2;k<=K;k++){
                j=i-1;          // now for every case of K we are considering the current element with one part and finding the max
                                // from the rest with k-1
                while(j>=0){

                    v[k][i] = max(v[k][i],v[k-1][j]+(S[i]-S[j])/(i-j));

                    
                    j--;
                }
            }
        }
        
        return v[K][n-1];
        
    }
};