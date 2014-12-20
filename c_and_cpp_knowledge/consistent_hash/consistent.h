//  consistent.h - a consistent hash ring
//

#ifndef CONSISTENT_H
#define CONSISTENT_H

#include <map>
#ifdef __GNUC__
#include <ext/hash_map>
#else
#include <hash_map>
#endif
#include <string>
#include <sstream>
#include <iostream> 
#include <openssl/md5.h>

namespace
{

  class StringifyException
  {
  };

  template <class T>
    /*Stringify is to convect type to string*/
    std::string Stringify(const T& t)
    {
      std::ostringstream os;
      if (!(os << t))
	{
	  throw StringifyException();
	}
      return os.str();
    }

  template <>
    std::string Stringify(const std::string& str)
    {
      return str;
    }

  template <>
    std::string Stringify(const char* const& str)
    {
      return str;
    }

}

namespace Consistent
{

  class EmptyRingException
  {
  };

  struct Hash
  {
      size_t operator()(const std::string& data) const
      {
	  /* generate md5 checksum for data, fold it to 32 bit*/
    	  MD5_CTX ctx;
	  unsigned char md[17]={'\0'};
	
	  MD5((const unsigned char*)(data.c_str()),data.length(),md);
	  // for(int i = 0; i < 16; i++) 
	  //     std::cout << std::hex << (int)md[i];
	  // std::cout << std::endl;

	  /* 每四个字节构成一个32位整数，
	     将四个32位整数相加得到instr的hash值
	     如果机器位数是32的话可能溢出*/
	  size_t hash = 0;
	  for(int i = 0; i < 4; i++)
	      {
		  hash += ((size_t)(md[i*4 + 3]&0xFF) << 24)
		      | ((size_t)(md[i*4 + 2]&0xFF) << 16)
		      | ((size_t)(md[i*4 + 1]&0xFF) <<  8)
		      | ((size_t)(md[i*4 + 0]&0xFF));
	      }
	  //std::cout << std::dec << hash << std::endl;
	  return hash;
      }

  };

  template <class Node, class Data>
    class HashRing
    {
    public:
    typedef std::map<size_t, Node> NodeMap;

    HashRing(unsigned int replicas)
    : replicas_(replicas)
    {  
    }

    HashRing(unsigned int replicas, const Hash& hash)
    : replicas_(replicas), hash_(hash)
    {
    }

    size_t AddNode(const Node& node);
    void RemoveNode(const Node& node);
    const Node& GetNode(const Data& data) const;

    private:
    NodeMap ring_;
    const unsigned int replicas_;
    /*replicas_代表的是一个节点有几个虚拟节点*/
    struct Hash hash_;
    };

  template <class Node, class Data>
    size_t HashRing<Node, Data>::AddNode(const Node& node)
    {
      size_t hash;
      std::string nodestr = Stringify(node);
      for (unsigned int r = 0; r < replicas_; r++) {
	hash = hash_((nodestr + Stringify(r)).c_str());
	//std::cout<<nodestr+Stringify(r).c_str()<<" with hash "<<hash<<std::endl;
	ring_[hash] = node;
      }
      
      return hash;
    }

  template <class Node, class Data>
    void HashRing<Node, Data>::RemoveNode(const Node& node)
    {
      std::string nodestr = Stringify(node);
      for (unsigned int r = 0; r < replicas_; r++) {
	size_t hash = hash_((nodestr + Stringify(r)).c_str());
	ring_.erase(hash);
      }
    }

  template <class Node, class Data>
    const Node& HashRing<Node, Data>::GetNode(const Data& data) const
    {
      if (ring_.empty()) {
	throw EmptyRingException();
      }
      size_t hash = hash_(Stringify(data).c_str());
      //std::cout<<Stringify(data)<<" hash is "<<hash<<std::endl;
      typename NodeMap::const_iterator it;
      // Look for the first node >= hash
      it = ring_.lower_bound(hash);
      if (it == ring_.end()) {
	// Wrapped around; get the first node
	it = ring_.begin();
      }
      return it->second;
    }

}

#endif // CONSISTENT_H
