#可以转化为fibnacci数列
class Solution:
	def matrixMul(self,A,B):
		res=[[0]*len(B[0]) for i in range(len(A))];
		for i in range(len(A)):
			for j in range(len(B[0])):
				for k in range(len(B)):
					res[i][j] += A[i][k] * B[k][j];
		return res;	

	def fib(self,A,n):
		if(n==1 or n==0):
			 return A;
		mid = self.fib(A,n/2);
		if(n%2==0):
			 return self.matrixMul(mid,mid);
		else:
			 return self.matrixMul(A,self.matrixMul(mid,mid));
	
	def climbStairs(self,n):
		A=[[1,1],[1,0]]
		res = self.fib(A,n)
		return res[0][0]
			

sol = Solution()
n=int(raw_input("input:"))
res = sol.climbStairs(n)	
print res
