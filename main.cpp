#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


//Node to store to the data
class Node{
    public:
        string key;
        int value;
        Node(string key,int val){
            key=key;
            value=val;
        }
};

//LRU cache data structure
class LRUCache{
    public:
        int max_size;
        list<Node> l;
        unordered_map<string,list<Node>::iterator> m;

        LRUCache(int max_size){
            this->max_size= max_size >1? max_size : 1;
        }

        // We will implement three operations

        void InsertKeYValue(string key,int value){

            //two cases whther the key value that is to be accssed is present in cache or not
            //present in cache
            if(m.count(key)!=0){

                auto it=m[key];//this will give the address of the key
                it->value=value;//updating the old value to new one
            }
            else{
                //if that key is not present in cache then we need to get it insertedin cache
                //Check if cahe is full or not
                //if yes then remove least recently used key
                if(l.size()==max_size){
                    Node last=l.back();
                    m.erase(last.key);
                    l.pop_back();

                }

                Node n(key,value);
                l.push_front(n);
                m[key]=l.begin();
            }

        }

        int* getValue(string key){
            if(m.count(key)!=0){
                auto it=m[key];

                int value=it->value;
                l.push_front(*it);
                l.erase(it);
                m[key]=l.begin();
                return &l.begin()->value;
            }

            return NULL;
        }

        int MostRecentKey(){
            return l.front().value;
        }
};


int main(){
    LRUCache lru(3);
    lru.InsertKeYValue("Banana",10);
    lru.InsertKeYValue("Litchi",20);
    lru.InsertKeYValue("Mango",30);
    cout<<lru.MostRecentKey()<<endl;
    cout<<*(lru.getValue("Banana"))<<endl;

    lru.InsertKeYValue("Banana",40);
    cout<<lru.MostRecentKey()<<endl;

    lru.InsertKeYValue("Carrot",20);

    if(lru.getValue("Litchi")==NULL){
        cout<<"Litchi does not exist"<<endl;
    }
    if(lru.getValue("Mango")==NULL){
        cout<<"Mango does not exist"<<endl;
    }
    if(lru.getValue("Carrot")==NULL){
        cout<<"Carrot does not exist"<<endl;
    }
    if(lru.getValue("Banana")==NULL){
        cout<<"Banana does not exist"<<endl;
    }

}
