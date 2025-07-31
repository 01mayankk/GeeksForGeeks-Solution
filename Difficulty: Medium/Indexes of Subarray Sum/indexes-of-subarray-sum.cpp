class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        
        int N=arr.size();
        int sum=0;
        for(int i=0,j=0;j<N;j++){
            sum+=arr[j];
            while(sum>target){
                sum-=arr[i];
                i++;
            }
            if(sum==target){
              return {i+1,j+1};
          }
      }
      return {-1};
    }
};