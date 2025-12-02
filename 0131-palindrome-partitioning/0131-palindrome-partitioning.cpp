class Solution {
public:
    vector<vector<string>> res;
    bool isPal(string myStr){
        int n = myStr.size();
        for(int i=0; i<n; i++){
            if(myStr[i] != myStr[n-1-i])
                return false;
        }
        return true;
    }

    void dfs(string s, vector<string>& vs, int idx){
        if(idx == s.size()){
            res.push_back(vs);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            string substrr = s.substr(idx, i-idx+1);
            if(isPal(substrr)){
                vs.push_back(substrr);
                dfs(s, vs, i+1);
                vs.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> vs;
        dfs(s, vs, 0);
        return res;
    }
};