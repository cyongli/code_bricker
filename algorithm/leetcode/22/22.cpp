#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &board, bool **visited, int i, int j){
        if(i<0 || i>=board.size() || j<0 || j>=board.size()) return;
        if(board[i][j]=='X') return;
        if(board[i][j]=='O' && visited[i][j]==1) return;
        visited[i][j]=1;
        dfs(board,visited,i,j-1);
        dfs(board,visited,i-1,j);
        dfs(board,visited,i,j+1);
        dfs(board,visited,i+1,j);
    }

    void solve(vector<vector<char>> &board) {
        int len = board.size();
        bool **visited = new bool*[len];
        int i,j;
        for(i=0;i<len;++i) visited[i] = new bool[len];
        for(i=0;i<len;++i){
            for(j=0;j<len;++j){
                visited[i][j] = 0;
            }
        }
        for(i=0;i<len;++i){
            for(j=0;j<len;++j){
                if( (i-1<0 || i+1>=len || j-1<0 || j+1>=len) && (board[i][j]=='O')){
                    dfs(board,visited,i,j);
                }
            }
        }
        for(i=0;i<len;++i){
            for(j=0;j<len;++j){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};

int main(int argc, char *argv[]){
	FILE *fi = fopen(argv[1],"r");
	int len = stoi(argv[2]);
	vector<vector<char>> board;
	for(int i=0;i<len;++i){
		vector<char> row;
		for(int j=0;j<len;++j){
			char c;
			if(i==len-1) fscanf(fi,"%c\n",&c);
			else fscanf(fi,"%c ",&c);
			row.push_back(c);
		}	
		board.push_back(row);
	}
	for(int i=0;i<len;++i){
		for(int j=0;j<len;++j){
			cout << board[i][j] << "\x20";
		}
		cout << endl;
	}
	Solution sol;
	sol.solve(board);
	cout << "after flip" << endl;
	for(int i=0;i<len;++i){
		for(int j=0;j<len;++j){
			cout << board[i][j] << "\x20";
		}
		cout << endl;
	}
	return 0;
}
