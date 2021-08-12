#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


double printMedians(priority_queue<double> firstQ , priority_queue<double,vector<double>,greater<double> > secQ) {
        if(firstQ.size() == secQ.size()) {
            if(firstQ.empty()){
                return 0;
            }
            else{
                return ((firstQ.top()+secQ.top())/2.0);
            }
        }

        else {
            if(firstQ.size() > secQ.size()){
                return firstQ.top();
            }
            else{
                return secQ.top();
            }
        }    
    }

void findMedian(double arr[], int n){
    //Points to remember
    // heap size should have max size 1 greater than another. We need to always keep it balanced.
    priority_queue<double> firstQ; //maxHeap
    priority_queue<double,vector<double>,greater<double> > secQ; //minHeap
    double median;

    for (int i = 0; i < n; ++i)
    {    
        if(firstQ.empty() || (firstQ.top()>arr[i])) firstQ.push(arr[i]); // if it belongs to the smaller half
        else secQ.push(arr[i]); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
        cout<<printMedians(firstQ, secQ)<<" ";
    }
}

// Driver Code
int main() 
{ 
    // stream of integers 
    double arr[] = {5, 15, 10, 20, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    findMedian(arr, n);

    return 0; 
}