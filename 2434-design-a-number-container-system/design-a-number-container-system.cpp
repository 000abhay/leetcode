class NumberContainers {
unordered_map<int,int>index_num;
unordered_map<int,set<int>>num_index;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
         if(index_num.count(index))
         {
            num_index[index_num[index]].erase(index);
            if(num_index[index_num[index]].size()==0)
            {
                num_index.erase(index_num[index]);
            }
         }
         index_num[index]=number;
         num_index[number].insert(index);
    }
    
    int find(int number) {
         if(!num_index.count(number))
         {
            return -1;
         }
         return *(num_index[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */