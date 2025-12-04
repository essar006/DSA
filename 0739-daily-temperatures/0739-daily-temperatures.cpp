class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>result(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                result[i]=0;
            }
            else{
                result[i]=st.top()-i;
            }
            st.push(i);
        }
        return result;
        
    }
};