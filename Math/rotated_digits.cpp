class Solution {
public:
    bool isAGoodNumberCheck(int x){
        return x==2 || x==5 || x==6 || x==9;
    }
    bool helper(int N){
        bool flag = false;
        while(N>0){
            int digit = N % 10;
            N = N/10;
            
            if(digit==0 || digit==1 || digit==8) continue;
            
            if(isAGoodNumberCheck(digit)) flag = true;
            else return false;
        }
        return flag;
    }
    int rotatedDigits(int N) {
        int solution = 0;
        for(int i=1;i<=N;i++){
            if(helper(i)) ++solution;
        }
        return solution;
    }
};