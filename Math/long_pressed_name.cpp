class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int i=0,j=0,k,l,prev;
        
        
        while(i<name.length()){
            
            while(j<typed.length()&&name[i]==typed[j]){
                i++;
                j++;
      
                
            }
            prev = j;
            while(j<typed.length()&&j>0){
                if(typed[j]==typed[j-1])
                    j++;
                else
                    break;
            }
            
            if(prev==j&&j<typed.length())
                return false;
            
            if(j>typed.length()-1&&i<name.length())
                return false;
            
           
        }
        prev=j;
        while(j<typed.length()&&j>0){
            if(typed[j]==typed[j-1])
                    j++;
                else
                    break;
            
        }
        
        if(j<typed.length())
            return false;
        return true;
        
    }
};