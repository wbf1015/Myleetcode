class Solution {
public:
    vector<int>vi;
    vector<int> getRow(int rowIndex) {
        rowIndex+=1;
        for(int i=1;i<=rowIndex;i++){
            if(i==1){
                vi.push_back(1);
                continue;
            }else{
                vector<int>temp = vi;
                vi.clear();
                vi.push_back(1);
                for(int j=2;j<i;j++){
                    vi.push_back(temp[j-2]+temp[j-1]);
                }
                vi.push_back(1);
            }
        }
        return vi;
    }
};