#include <iostream>
#include <vector>
#include<string>

using namespace std;



class Solution {
public:
    int numTrees(int start,int end){
        if(start>end){
            return 1;
        }
        int count = 0;
        for(int i=start; i<=end; i++){
            int left_trees = numTrees(start,i-1);
            int right_trees = numTrees(i+1,end);
            count += left_trees * right_trees;
        }
        return count;
    }
    int numTrees(int n) {
        return numTrees(1,n);
    }
};