import random;
import sys;

f = open(sys.argv[1],"w+")
base = 2**32;
for i in range(int(sys.argv[2])):
	tmp = random.randint(0,base);
	f.write(str(tmp)+"\n")

f.close();

