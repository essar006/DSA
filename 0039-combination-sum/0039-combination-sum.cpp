class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void solve(vector<int>& a,int sum,int ind,int n)
    {
        if(sum==0)
        {
            ans.push_back(v);
            return;
        }
        
        if(ind==n || sum<0)
        {
            return;
        }
       
        v.push_back(a[ind]);
        solve(a,sum-a[ind],ind,n);
        v.pop_back();
        
        solve(a,sum,ind+1,n);
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int k) {
        
        int n=a.size();
        solve(a,k,0,n);   
        return ans;
    }
};