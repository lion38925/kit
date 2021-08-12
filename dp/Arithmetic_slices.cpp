class Solution {
public:

// in this solution a A sequence of numbers is called arithmetic 
// if it consists of at least three elements and if the difference between any two consecutive elements is the same.
// so we need to find total arithmetic number of sequence

// for this we take a flag and check if earlier was also same difference then current
// value be 1+ old one else zero and then sum all
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if(A.size()==0)
            return 0;
        vector<int> dp(A.size(),0);
        
        int i,j,sum=0,flag=0,n;
        n = A.size();

        dp[0]=0;
        
        
        for(i=1;i<n-1;i++){
            if(A[i]-A[i-1]==A[i+1]-A[i]){
                if(flag){
                    dp[i]=1+dp[i-1];
                }else{
                    dp[i]=1;
                    flag=1;
                }
            }else{
                dp[i]=0;
                flag=0;
            }
            
        }
        
        for(i=0;i<n;i++)
            sum+=dp[i];
        return sum;
        
        
    }
};