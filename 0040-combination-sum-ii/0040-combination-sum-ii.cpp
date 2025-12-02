class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& arr, int tar, vector<int>& v,int idx){

        if(tar == 0) {res.push_back(v); return;}
        if(idx == arr.size() || tar < 0) return;

        for(int i=idx; i<arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1]) continue;
            v.push_back(arr[i]);
            dfs(arr, tar-arr[i], v, i+1);
            v.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, v, 0); 

        return res;
    }
};

