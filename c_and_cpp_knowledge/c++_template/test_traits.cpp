#include<string>
#include<iostream>
#include<cctype>
using namespace std;

struct ci_char_traits : public char_traits<char>{
  static bool eq(char c1, char c2){
    return toupper(c1) == toupper(c2);
  }
  static bool lt(char c1, char c2){
    return toupper(c1) < toupper(c2);
  }
  static int compare(const char* s1, const char* s2, size_t n){
    while (n-- != 0){
      if( toupper(*s1) < toupper(*s2) ) return -1;
      if( toupper(*s1) > toupper(*s2) ) return 1;
      ++s1; ++s2;
    }
    return 0;
  }
  static const char* find(const char* s, int n, char a){
    auto const ua(toupper(a));
    while ( n-- != 0){
      if(toupper(*s) == ua)
	return s;
      s++;
    }
    return nullptr;
  }
};

typedef basic_string<char, ci_char_traits> ci_string;

ostream& operator<<(ostream& os, const ci_string& str){
  return os.write(str.data(), str.size());
}

int main(int argc, char* argv[]){
  ci_string s1 = "Hello";
  ci_string s2 = "heLLo";
  if(s1 == s2)
    cout<<s1<<" and "<<s2<<" are equal"<<endl;
  else cout<<"not equal"<<endl;
  return 0;
}
