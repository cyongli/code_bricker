#For C++ programmer: 
#   1. all member variable are public
#   2. all methods in python are effectively virtual
class Foo(object):
	def __init__(self, frob, frotz):
		self.frobnicate = frob
		self.frotz = frotz

class Bar(Foo):
	def __init__(self, frob, frizzle):
		super(Bar, self).__init__(frob, frizzle)
		self.frotz = 34
		self.frazzle = frizzle

bar = Bar(1,2)
print "frobnicate:",bar.frobnicate
print "frotz:",bar.frotz
print "frazzle:",bar.frazzle
