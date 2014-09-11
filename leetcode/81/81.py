#题目大意：给定一个path，将其简化
#  /home/chaoyli/ -> /home/chaoyli
#  /a/b./../../c  -> /c
#解法：
#1.将字符串用"/"进行分割
#2.用栈进行操作，"."不做任何操作，".."出一个栈，"/.."不做任何操作
class Solution:
	def simplifyPath(self, path):
		parts=path.split("/")
		ret=[]
		for part in parts:
			if (not part) or (part==".") :
				continue
			elif part==".." and (not ret)==False:
				ret.pop()
			elif part==".." and not ret:
				continue
			else:
				 ret.append(part)
		res=""
		for part in ret:
			if (not part)==False:
				res += "/"+str(part)
		res = res + ("/" if not res else "")
		return res

sol=Solution()
path=raw_input("input:")
ret=sol.simplifyPath(path)
print ret
