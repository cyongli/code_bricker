class Solution:
	def plusOne(self, digits):
		digits.reverse()
		a=1	
		for i in range(len(digits)):
			num=digits[i]+a;
			a=num/10;
			digits[i]=num%10
		if a!=0: digits.append(a)
		digits.reverse()
		return digits

sol=Solution()
digits=[9]
res=sol.plusOne(digits)
print res
