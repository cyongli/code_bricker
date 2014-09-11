#encoding: utf-8
#一个集合里面求a+b+c=0的所有集合
#解法:
#    1.先排序
#    2.寻找b+c=-a的数
#寻找b+c等于指定数的值
#i=0,j=length-1
#if(A[i]+A[j]==-a) (i,j)是满足条件的下标
#else if(A[i]+A[j}<-a) i++
#else j++
class Solution:
	def threeSum(self, num):
		res=[]
		length=len(num)
		num.sort()
		for i in range(length):
			if i>0 and num[i]==num[i-1]: continue#用来去掉重复数据
			j,k=i+1,length-1
			while j<k:
				if j>i+1 and num[j]==num[j-1]: 
					j = j+1
					continue
				if k<length-1 and num[k]==num[k+1]:
					k = k-1
					continue
				if num[j]+num[k]== -num[i]:
					res.append([num[i],num[j],num[k]])
					j=j+1;k=k-1
				elif num[j]+num[k] < -num[i]:
					j = j+1
				else: k = k-1 	
		return res 


sol=Solution()
num=[]
f=open("/home/lichaoyong/input","r")
line=f.readline()
while line:
	num.append(int(line))
	line=f.readline()
res=sol.threeSum(num)
print res,len(res)
