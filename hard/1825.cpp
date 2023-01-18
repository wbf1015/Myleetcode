//下面这个我自己的写的可以13/17，说明时间要求很高，连sort这样的nlogn的时间复杂度都是不被允许的
class MKAverage {
public:
    deque<int>di;//使用双端队列
    int m;
    int k;
    double sum=0.0;
    MKAverage(int m, int k) {
        this->m=m;
        this->k=k;
    }
    
    void addElement(int num) {
        if(di.size()<m){
            di.push_back(num);
            sum+=num;
        }
        else{
            sum+=num;
            sum-=di.front();
            di.pop_front();
            di.push_back(num);
        }
        //Myprint(di);
    }
    
    void Myprint(deque<int>&di){
        for(deque<int>::iterator it=di.begin();it!=di.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    int calculateMKAverage() {
        if(di.size()<m){return -1;}
        else{
            deque<int>temp=di;
            sort(temp.begin(),temp.end());
            double temp_d=sum;
            for(int i=1;i<=k;i++){
                temp_d-=temp.front();
                temp_d-=temp.back();
                temp.pop_front();
                temp.pop_back();
            }
            temp_d=floor(temp_d/temp.size());
            return temp_d;
        }
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

//下面这个是我看了官方题解理解了题解后写的解法
class MKAverage {
public:
    deque<int>di;//使用双端队列
    multiset<int>low,mid,high;
    int m;
    int k;
    double sum=0.0;
    MKAverage(int m, int k) {
        this->m=m;
        this->k=k;
    }
    
    void addElement(int num) {
        //插入的数量还少于m
        if(di.size()<m){
            di.push_back(num);
            mid.insert(num);
            sum+=num;
            if(di.size()==m){
                for(int i=1;i<=k;i++){
                    low.insert(*mid.begin());
                    sum-=*mid.begin();
                    mid.erase(mid.begin());
                    
                    high.insert(*mid.rbegin());
                    sum-=*mid.rbegin();
                    mid.erase(prev(mid.end()));
                    }
            }
            return;
        }
        if(num<*low.rbegin()){
            low.insert(num);
            mid.insert(*low.rbegin());
            sum+=*low.rbegin();
            low.erase(prev(low.end()));//这里为什么不用rbegin呢？
        }
        else if(num>*high.begin()){
            high.insert(num);
            mid.insert(*high.begin());
            sum+=*high.begin();
            high.erase(high.begin());
        }
        else{
            mid.insert(num);
            sum+=num;
        }
        int q=*di.begin();
        di.pop_front();
        di.push_back(num);
        if(low.count(q)>0){
            low.erase(low.find(q));
            low.insert(*mid.begin());
            sum-=*mid.begin();
            mid.erase(mid.begin());
            return ;
        }
        if(high.count(q)>0){
            high.erase(high.find(q));
            high.insert(*mid.rbegin());
            sum-=*mid.rbegin();
            mid.erase(prev(mid.end()));
            return;
        }
        sum-=q;
        mid.erase(mid.find(q));
        return;
    }
    
    void Myprint(deque<int>&di){
        for(deque<int>::iterator it=di.begin();it!=di.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    int calculateMKAverage() {
        if(di.size()<m){return -1;}
        else{
            return floor(sum/(m-2*k));
        }
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */