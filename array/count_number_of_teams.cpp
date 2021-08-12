//o(n3) solution 

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int i,j,k,t=0,n;
        n = rating.size();
        
        
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1;k<n;k++){
                    if(rating[i]<rating[j]&&rating[j]<rating[k])
                        t++;
                    else
                        if(rating[i]>rating[j]&&rating[j]>rating[k])
                            t++;
                }
            }
        }
        return t;
    }
};

//// O(n2) solution 

class Solution {
public:
    int numTeams(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        for(int i = 1 ; i < n-1 ; i++){
            int leftSmall = 0, leftLarge = 0;
            int rightSmall = 0, rightLarge = 0;
            //left part
            for(int j = 0 ; j < i ; j++){
                if(arr[j] < arr[i]){
                    leftSmall++;
                }
                if(arr[j] > arr[i]){
                    leftLarge++;
                }
            }
            //right part
            for(int j = i+1 ; j < n ; j++){
                if(arr[j] < arr[i]){
                    rightSmall++;
                }
                if(arr[j] > arr[i]){
                    rightLarge++;
                }
            }
            result += leftSmall * rightLarge + leftLarge * rightSmall;
        }
        return result;
    }
};


/// O(nlogn) fenwik tree and bit solution


class Solution {
public:
    
    vector<int> BIT;
    void update(int i)
    {
        while (i < 1e5 + 5)
        {
            BIT[i]++;
            i += (i&(-i));
        }
    }
    int query(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += BIT[i];
            i -= (i&(-i));
        }
        return sum;
    }
    
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), res = 0;
        BIT.resize(1e5+ 5);
        fill(BIT.begin(), BIT.end(), 0);
        vector<int> numSmallLeft(n), numEqualLeft(n), numSmallRight(n), numEqualRight(n);
        
        for (int i = 0; i < n; i++)
        {
            int num_small = query(rating[i] - 1), num_eq = query(rating[i]);
            num_eq -= num_small;
            numSmallLeft[i] = num_small; numEqualLeft[i] = num_eq;
            update(rating[i]);
        }
        
        fill(BIT.begin(), BIT.end(), 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int num_small = query(rating[i] - 1), num_eq = query(rating[i]);
            num_eq -= num_small;
            numSmallRight[i] = num_small; numEqualRight[i] = num_eq;
            update(rating[i]);
        }
        
        for (int i = 0; i < n; i++)
        {
            res += numSmallLeft[i] * (n - 1 - i - numEqualRight[i] - numSmallRight[i]);
            res += numSmallRight[i] * (i - numSmallLeft[i] - numEqualLeft[i]);
        }
        
        return res;
    }
};