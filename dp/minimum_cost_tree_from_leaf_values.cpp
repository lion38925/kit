// Solution of this question is done without dp using basic logic 

// [6,2,4,1,7]
// minimum = 1,4
// sum += 4(1*4)
// remove 1
// [6,2,4,7] remaining
// minimum = 2,4
// sum += 8
// remove 2
// [6,4,7] remaining
// minimum = 6,4
// sum += 24
// remove 4
// [6,7] remaining
// sum += 42
// remove 6
// only one element 7 left, return sum;



class Solution {
public:
      int mctFromLeafValues(vector<int>& arr)
    {
        int sum = 0;
        while(arr.size()>1)
        {
            int min = INT_MAX;
            int v,x;
            for(int i=0;i<arr.size()-1;i++)
            {
                v = arr[i]*arr[i+1];
                
                if(min > v)
                {
                    min = v;
                    x = arr[i] < arr[i+1]? i:i+1;
                }
            }
            arr.erase(arr.begin()+x);
            sum += min;
        }
        return sum;
    }
};