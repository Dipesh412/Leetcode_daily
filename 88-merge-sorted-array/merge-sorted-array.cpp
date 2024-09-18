class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0; int j=0;
        vector<int>n2;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                n2.push_back(nums1[i]); 
                i++;
            }
            else{
                n2.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            n2.push_back(nums1[i]);
            i++; 
        }
        while(j<n){
            n2.push_back(nums2[j]);
            j++; 
        }
        nums1.resize(m+n);
        for(int i=0; i<n2.size(); i++){
            nums1[i]=n2[i];
        }
    }
};