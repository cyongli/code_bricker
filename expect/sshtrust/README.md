此程序的目的是为了配置任意台机器的互信
使用方式参见operate.txt

原理如下:
1.选取1台机器作为启动节点，执行ssh-keygen命令，产生密钥对
2.利用expect交换工具，执行ssh hostName exit消除到所以的验证的yes
3.将本机上的.ssh全部拷贝到其他机器上
