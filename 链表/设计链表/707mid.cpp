class MyLinkedList {
public:
    struct LinkNode{
        int val;
        LinkNode* next;
        LinkNode(int val){
            this->val = val;
            this->next = nullptr;
        };
    };

    // 通过虚拟头部来获得这个链表
    int size;
    LinkNode* dummyhead;

    // 初始化函数
    MyLinkedList() {
        this->dummyhead = new LinkNode(-1);
        this->size = 0;
    }
    
    // 获取某一个索引的结点的值
    int get(int index) {
        if( index < 0 || index >= this->size){
            return -1;
        }
        int count = 0;
        for(LinkNode* it = this->dummyhead->next; it!=nullptr; it=it->next){
            if(count++==index){
                return it->val;
            }
        }
        return -1;
    }
    
    // 添加结点到链表头
    void addAtHead(int val) {
        LinkNode* newhead = new LinkNode(val);
        newhead->next = this->dummyhead->next;
        this->dummyhead->next = newhead;
        this->size+=1;
    }
    
    // 添加结点到链表的尾部
    void addAtTail(int val) {
        for(LinkNode* it=this->dummyhead; it!=nullptr; it=it->next){
            if(it->next==nullptr){
                LinkNode* newnode = new LinkNode(val);
                it->next = newnode;
                this->size+=1;
                return ;
            }
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==this->size){
            addAtTail(val);
            return;
        }
        if(index>this->size){
            return;
        }
        int count=0;
        for(LinkNode*it = this->dummyhead; it!=nullptr; it=it->next){
            if(count++==index){
                LinkNode* newnode = new LinkNode(val);
                newnode->next = it->next;
                it->next = newnode;
                this->size+=1;
                return;
            }
        }

    }
    
    void deleteAtIndex(int index) {
        if( index < 0 || index >= this->size){
            return;
        }
        int count=0;
        for(LinkNode*it=this->dummyhead; it->next!=nullptr; it=it->next){
            if(count++==index){
                LinkNode* tmp = it->next;
                it->next = it->next->next;
                this->size-=1;
                delete tmp;
                return;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */