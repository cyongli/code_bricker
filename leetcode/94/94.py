#encoding: utf-8
#将由1,2,3,4...n*n构成的二维数组用螺旋的方式存储起来
#解法：对每一个环进行打印
#	i,i -> i,i+a
#    .       .
#    .       .
#    .       .
#   i+a,i  i+a,i+a
class Solution:
	def generateMatrix(self, n):
		ret=[[0]*n for i in range(n)]
		a=n
		val=1
		for i in range(n/2):
			for column in range(i,i+a):
				ret[i][column] = val; val += 1
			for row in range(i+1,i+a):
				ret[row][i+a-1] = val; val += 1
			for column in range(i,i+a-1)[::-1]:
				ret[i+a-1][column] = val; val += 1
			for row in range(i+1,i+a-1)[::-1]:
				ret[row][i] = val; val += 1;
			a = a-2
		if n%2==1: ret[n/2][n/2] = val	
		return ret

sol=Solution()
n=int(raw_input("input:"))
ret=sol.generateMatrix(n)
print ret
