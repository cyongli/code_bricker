#include "consistent.h"

class CacheServer
{
public:
    typedef std::map<std::string, std::string> StringMap;

    void Put(const std::string& key, const std::string& value)
    {
	cache_[key] = value;
    }

    std::string Get(const std::string& key) const
    {
	std::string value;
	StringMap::const_iterator it = cache_.find(key);
	if (it != cache_.end()) {
	    value = it->second;
	}
	return value;
    }

    void Remove(const std::string& key)
    {
	StringMap::iterator it = cache_.find(key);
	if (it != cache_.end()) {
	    cache_.erase(it);
	}
    }

private:
    StringMap cache_;
};

int main(int argc,char*argv[]){
    Consistent::HashRing<std::string, std::string> ring(4);
    std::vector<std::string> host;
    for(int i=2;i<=5;i++){
	ring.AddNode("localhost"+std::to_string(i));
	//std::cout<<"localhost"+std::to_string(i)<<std::endl;
    }
    const char* tetD[] = {"DELIVER IN PERSON","TAKE BACK RETURN","3"};
    const unsigned int numDa = sizeof(tetD) / sizeof(char*);
    for(unsigned f = 0;f < numDa; f++){
	std::string host = ring.GetNode(tetD[f]);
	std::cout<<"Storing "<<tetD[f]<<" on server "<<host<<std::endl;
    }
    return 0;
}
