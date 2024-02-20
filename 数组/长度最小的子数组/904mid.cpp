class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fb=-1, fb_end=-1; //first backet
        int sb=fruits[0], sb_end=0; //second backet
        int res=1;
        int sublen=0;
        int start=0;
        for(int end=1;end<=fruits.size()-1;end++){
            if(sb!=fruits[end]){
                // 只有一个篮子在用的情况
                if(fb==-1){
                    fb=sb;  fb_end=sb_end;
                    sb=fruits[end]; sb_end=end;
                    sublen = end-start+1;
                    if(res<sublen) res=sublen;
                }
                // 两个篮子都在用，且与前一个篮子相等，交换两个篮子的信息，因为我们总是要放弃更靠前的那个果子
                else if(fb==fruits[end]){
                    fb=sb; fb_end=sb_end;
                    sb=fruits[end]; sb_end=end;
                    sublen = end-start+1;
                    if(res<sublen) res=sublen;
                }else{ //出现了新的果子，放弃靠前的果子
                    start = fb_end+1;
                    fb=sb;  fb_end=sb_end;
                    sb=fruits[end]; sb_end=end;
                    sublen = end-start+1;
                    if(res<sublen) res=sublen;
                }
            }else{
                // 与第二个篮子相等，直接加就可以
                sb_end = end;
                sublen = end-start+1;
                if(res<sublen) res=sublen;
            }
        }
        return res;
    }
};