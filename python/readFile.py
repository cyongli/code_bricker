# -*- coding: utf-8 -*-
#将文件编码为utf-8
import sys
print sys.argv[0]
f = open(sys.argv[1], "rw+")
line = f.readline()
while line:
	print line,#加逗号表示不换行输出
	line = f.readline()
f.close()
