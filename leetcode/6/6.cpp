/*
 *LRU算法的实现，使用链表实现。
 * 每次找到访问过的元素，就将其移动到最前面
 * 同时为了加快查询速度，用map记录元素在缓存队列中的位置
 * */

#include<iostream>
#include<cstring>
#include<list>
#include<map>
using namespace std;

typedef struct{
	int key;
	int value;
}elem;

class LRUCache{
private:
	int capacity;
	list<elem> cache;
	map<int,list<elem>::iterator> keyMap;
public:
    LRUCache(int capacity)
	:capacity(capacity),
	 cache(0),
	 keyMap()
	{ }   
 
	list<elem>::iterator find(int key){
		map<int,list<elem>::iterator>::iterator it = keyMap.find(key);
		if(it == keyMap.end()){
			return cache.end();
		} else {
			return it->second;
		}
	}

    int get(int key) {
		list<elem>::iterator it = find(key);
		if(it != cache.end()){
			cache.splice(cache.begin(),cache,it);
			return (*cache.begin()).value;
		}	
		else return -1; 
	}
    
    void set(int key, int value) {
		list<elem>::iterator it = find(key);
		if(it != cache.end()){
			(*it).value = value;
			cache.splice(cache.begin(),cache,it);
		}
		else{
			elem e = {key,value};
			if(cache.size() == capacity){
				keyMap.erase(cache.back().key);
				cache.pop_back();
			}
			cache.push_front(e);
			keyMap.insert(pair<int,list<elem>::iterator>(key,cache.begin()));
		}
		//print();
    }
	
	void print(){
		list<elem>::iterator it=cache.begin();
		for(int i=0;i<cache.size();i++,it++){
			cout << "key is " << (*it).key << " and ";
			cout << "value is " << (*it).value << endl;
		}
		//cout << endl;
	}
};

int main(int argc, char* argv[]){
	LRUCache cache(stoi(argv[1]));
	FILE* fi = fopen(argv[2],"r");
	char op[10];
	int key,value;
	for(int i=0;i<stoi(argv[3]);i++){
		fscanf(fi,"%s ",op);
		if(strcmp(op,"set") == 0){
			fscanf(fi,"%d ",&key);
			fscanf(fi,"%d\n",&value);
			cache.set(key,value);
		}
		else{
			fscanf(fi,"%d\n",&key);
			cache.get(key);
		}
	}
	fclose(fi);
	//cache.print();
	return 0;
}
