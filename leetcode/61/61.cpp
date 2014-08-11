/*求有重复元素的数组的子集合
 *由于有重复元素，所以不能再用二进制表示，因为二进制表示
 *要求一一对应,只能用递归
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int>> ret;
public:
	void subsetsWithDup_aux(vector<int> &s, int curPos, vector<int> &tmp)
	{	
  		ret.push_back(tmp);
    	for(int i = curPos; i < s.size(); ++i)
    	{
        	if(i != curPos && s[i] == s[i - 1])continue;
        	tmp.push_back(s[i]);
        	subsetsWithDup_aux(s, i + 1, tmp);
        	tmp.pop_back();
   		}
	}
 
	vector<vector<int> > subsetsWithDup(vector<int> &s)
	{
    	sort(s.begin(), s.end());
    	vector<int> tmp;
    	subsetsWithDup_aux(s, 0, tmp);
		print();
    	return ret;
	}

	void print(){
		vector<vector<int>>::iterator out = ret.begin();
		for(;out!=ret.end();out++){
			vector<int>::iterator in = (*out).begin();
			for(;in!=(*out).end();in++){
				cout << *in << "\x20";
			}
			cout << endl;
		} 
	}
};

int main(int argc, char *argv[]){
	ifstream fi(argv[1],ios::in);
	Solution sol;
	vector<int> s;
	int elem;
	for(int i=0;i<stoi(argv[2]);i++){
		fi >> elem;
		s.push_back(elem);
	}
	//vector<int>::iterator it = s.begin();
	//for(;it!=s.end();it++){
	//	cout << (*it) << endl;
	//}
	sol.subsetsWithDup(s);
	return 0;
}
