class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int size = arr.size();
        for(int i = 0; i <= size - m*k ; i++){
            int count = 1;
            for(int j = i+m ; j < size ; j += m){
                bool match = true;
                for(int k = 0; k < m ; k++){
                    if(arr[i + k] != arr[j + k]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    count++;
                }else{
                    break;
                }
            }
            if(count >= k){
                return true;
            }
        }
        return false;
    }
};