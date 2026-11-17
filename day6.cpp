class Solution {
public:
    void backtrack(int index,vector<int>& nums,vector<int>& temp,vector<vector<int>>& result){
        
        result.push_back(temp);
        
        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            
            backtrack(i + 1, nums, temp, result);

            temp.pop_back();
        }
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(0, nums, temp, res);
    
        return res;
    }
};
