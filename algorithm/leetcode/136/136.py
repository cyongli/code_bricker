#encoding: utf-8
#一个集合里面求a+b+c=target最相近的总和
import sys
class Solution:
	def threeSum(self, num, target):
		length=len(num)
		num.sort()
		near=num[0]+num[1]+num[2]
		for i in range(length):
			if i>0 and num[i]==num[i-1]: continue#用来去掉重复数据
			j,k=i+1,length-1
			while j<k:
				if j>i+1 and num[j]==num[j-1]: 
					j = j+1; continue
				if k<length-1 and num[k]==num[k+1]:
					k = k-1; continue
				if num[j]+num[k]== target-num[i]:
					near=target
					return near
				elif num[j]+num[k] < target-num[i]:
					if abs(near-target) > abs(num[j]+num[k]+num[i]-target) : near=num[i]+num[j]+num[k]
					j = j+1
				else:
					if abs(near-target) > abs(num[j]+num[k]+num[i]-target) : near=num[i]+num[j]+num[k] 
					k = k-1 	
		return near 


sol=Solution()
num=[]
f=open("/home/lichaoyong/input","r")
line=f.readline()
while line:
	num.append(int(line))
	line=f.readline()
target=int(raw_input("input:"))
res=sol.threeSum(num,target)
print res
