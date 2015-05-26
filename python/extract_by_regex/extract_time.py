import sys;
import re;

f = open(sys.argv[1],"rw+")
fw = open(sys.argv[2],"rw+")
line = f.readline();

k = re.compile("\[(time.*)\]");
k.search(line).group(1)
while line:
    fw.write(k.search(line).group(1));
    fw.write("\n");
    line = f.readline(); 

f.close();
fw.close();
