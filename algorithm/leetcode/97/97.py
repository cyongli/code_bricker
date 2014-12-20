#题目大意：给定一系列的区间，将可能的区间进行合并
#解法：1.将区间按照左边界进行排序
#	   2.从第一个区间开始，将其入栈
#	   3.如果两个区间能够合并，就进行合并，否则下一个
class Interval:
	def __init__(self, s=0, e=0):
		self.start = s	
		self.end = e

class Solution:
	def getKey(self,item):
		return item.start; 
		
	def merge(self, intervals):
		if not intervals:
			return []
		res = sorted(intervals, key=self.getKey);
		s=[res[0]]
		for interval in res[1::1]:
			top = s[-1]
			if top.end >= interval.start :
				s.pop()
				top.end = max(top.end, interval.end)
				s.append(top)
			else:
				s.append(interval)
		return s
	
sol=Solution()
intervals=[Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)]
ret=sol.merge(intervals)
for i in ret:
	print str(i.start)+","+str(i.end)
