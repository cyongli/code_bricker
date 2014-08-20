/*
题目大意:给定一个二维字符数组，数组内容为'X'或者'O'
         如果'O'块全部被'X'包围，则把'O'变成'X'
解法:dfs
     从二维数组的最外层的'O'开始，如果能够遍历到其他的'O',则这些'O'不需要变动
     否则就将'O'变为'X'
general_22.cpp解决的是二维数组长和宽度不一致，每行长度不一致的情形
22.cpp解决的是一个正方形的二维数组
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &board, bool **visited, int *rowLen, int i, int j){
        if(i<0 || i>=board.size() || j<0 || j>=rowLen[i]) return;
        if(board[i][j]=='X') return;
        if(board[i][j]=='O' && visited[i][j]==1) return;
        visited[i][j]=1;
        dfs(board,visited,rowLen,i,j-1);
        dfs(board,visited,rowLen,i-1,j);
        dfs(board,visited,rowLen,i,j+1);
        dfs(board,visited,rowLen,i+1,j);
    }

    void solve(vector<vector<char>> &board) {
        int len = board.size();
        bool **visited = new bool*[len];
		int *rowLen = new int[board.size()];
        int i,j;
        for(i=0;i<len;++i) {
			rowLen[i] = board[i].size();
			visited[i] = new bool[rowLen[i]];
		}
        for(i=0;i<len;++i){
            for(j=0;j<rowLen[i];++j){
                visited[i][j] = 0;
            }
        }
        for(i=0;i<len;++i){
            for(j=0;j<rowLen[i];++j){
                if( (i-1<0 || i+1>=len || j-1<0 || j+1>=rowLen[i]) && (board[i][j]=='O')){
                    dfs(board,visited,rowLen,i,j);
                }
            }
        }
        for(i=0;i<len;++i){
            for(j=0;j<rowLen[i];++j){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};

int main(int argc, char *argv[]){
	FILE *fi = fopen(argv[1],"r");
	int rowLen = stoi(argv[2]);
	int colLen = stoi(argv[3]);
	vector<vector<char>> board;
	for(int i=0;i<rowLen;++i){
		vector<char> row;
		for(int j=0;j<colLen;++j){
			char c;
			if(i==colLen-1) fscanf(fi,"%c\n",&c);
			else fscanf(fi,"%c ",&c);
			row.push_back(c);
		}	
		board.push_back(row);
	}
	for(int i=0;i<rowLen;++i){
		for(int j=0;j<colLen;++j){
			cout << board[i][j] << "\x20";
		}
		cout << endl;
	}
	Solution sol;
	sol.solve(board);
	cout << "after flip" << endl;
	for(int i=0;i<rowLen;++i){
		for(int j=0;j<colLen;++j){
			cout << board[i][j] << "\x20";
		}
		cout << endl;
	}
}
