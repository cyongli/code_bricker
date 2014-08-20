#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

typedef unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> Map;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *graph) {
		if(NULL==graph) return NULL;

		std::queue<UndirectedGraphNode*> q;
		q.push(graph);
		
		Map map;	
		UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);
		map[graph] = graphCopy;	

		while(!q.empty()){
			UndirectedGraphNode *node = q.front();
			q.pop();
			int n = (node->neighbors).size();
			for(int i=0;i<n;++i){
				UndirectedGraphNode *neighbor = (node->neighbors)[i];
				if(map.find(neighbor)==map.end()){
					UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
					map[node]->neighbors.push_back(p);
					map[neighbor] = p;
					q.push(neighbor);
				}
				else{
					map[node]->neighbors.push_back(map[neighbor]);
				}
			}
		}
		return graphCopy;
    }
};

int main(int argc, char *argv[]){

	return 0;
}
