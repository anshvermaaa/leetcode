class Solution {
public:
    bool isMatched(vector<string>& products,int i,string searchWord,int l){
     return  l<products.size()&&products[l].size()>i&&searchWord[i]==products[l][i];
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=products.size();
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        int l=0;
        int r=n-1;
        for(int i=0;i<searchWord.size();i++){
            while(l<=r&&!isMatched(products,i,searchWord,l)) l++;
            while(r>=l&&!isMatched(products,i,searchWord,r)) r--;
            if(l>r) ans.push_back({});
            else{
                vector<string> temp;
                for(int j=l;j<=min(r,l+2);j++){
                    temp.push_back(products[j]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};