#encoding: utf-8
#题目：将m*n的矩阵用螺旋的方式打印
#解法: i,i   ->   i+n,i+m
#       .            .
#       .            .
#       .            .
#    i+m,i   ->   i+n,i+m

class Solution:
	def spiralOrder(self, matrix):
		if(len(matrix)==0): return matrix
		cycle = ((len(matrix) if len(matrix) < len(matrix[0]) else len(matrix[0]))+1)/2
		a=len(matrix[0])
		b=len(matrix)
		res=[]
		for i in range(0, cycle):
			for column in range(i, i+a):
				res.append(matrix[i][column])
			for row in range(i+1, i+b):
				res.append(matrix[row][i+a-1])
			if(a==1 or b==1): break;
			for column in range(i,i+a-1)[::-1]:
				res.append(matrix[i+b-1][column])
			for row in range(i+1,i+b-1)[::-1]:
				res.append(matrix[row][i])	
			a -= 2
			b -= 2
		return res

sol=Solution()
matrix=[[1,2,3,4],[5,6,7,8],[9,10,11,12]]
ret = sol.spiralOrder(matrix)
print ret
