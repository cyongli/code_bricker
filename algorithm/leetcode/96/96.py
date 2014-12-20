#题目大意：给定一组区间，输入一个新的区间，对其进行可能的合并
#解法：遍历一边原来的一组区间就可以搞定了
class Interval:
	def __init__(self, s=0, e=0):
		self.start = s
		self.end = e

class Solution:
	def insert(self, intervals, newInterval):
		if not intervals:
			return [newInterval]
		ret=[]
		for i in intervals:
			if i.start <= newInterval.start and i.end >= newInterval.start:
				newInterval.start = i.start
				newInterval.end = max(newInterval.end, i.end)
			elif newInterval.start <= i.start and newInterval.end >= i.start:
				newInterval.end = max(newInterval.end, i.end)
			else:
				ret.append(i)
		ret.append(newInterval)
		ret.sort(key = lambda x:x.start)
		return ret
				

sol=Solution()
intervals=[Interval(1,3), Interval(6,9)]
newInterval=Interval(2,5)
ret=sol.insert(intervals, newInterval)
for i in ret:
	print str(i.start)+","+str(i.end)
