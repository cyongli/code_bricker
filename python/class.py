
class test:
	i = 0;
	def __init__(self):
		self.i = 7;#variable in class must be accessed in self.variable format
	def a(self,n):#function in class must add self parameter
		print self.i
x = test();
print test.i#classname.variable is the init value of the variable
print x.i#object.variable is the configured value
