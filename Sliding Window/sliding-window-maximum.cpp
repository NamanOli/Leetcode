// https://www.interviewbit.com/problems/sliding-window-maximum/#


/*
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example:

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]
    
    We will store the maximum in a queue of every subarray . traverese the array and the element in the left smaller than the present max will not be put in the queue while 
    the other elements will be putted.and we will do i++ , before that see if arr[i] present in the queue, if present then popfront. then do j++ and if the back element smaller
    than arr[j] then popback until its not empty or back greater than arr[j] then pushback.

*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    if(A.size()<B){
        return ans;
    }
    deque<int> Q;
    int i=0;
    
    Q.push_back(A[i]);
    for(int j=1; j<A.size();j++){
        if(j-i<B){
            while(!Q.empty() && Q.back()<A[j]){
                Q.pop_back();
            }
            Q.push_back(A[j]);
        }
        
        else{
            ans.push_back(Q.front());
            if(A[i]==Q.front()){
                Q.pop_front();
            }
            while(!Q.empty() && Q.back()<A[j]){
                Q.pop_back();
            }
            Q.push_back(A[j]);
            i++;
        }
    }
    ans.push_back(Q.front());
    return ans;
}
