此程序的目的是为了配置任意台机器的互信

原理如下:

1.选取有相同账户的多台机器
2.选取1台机器作为启动节点，执行ssh-keygen命令，产生密钥对
3.利用expect交换工具，执行ssh hostName exit消除到所以的验证的yes
4.将本机上的.ssh全部拷贝到其他机器上
本程序的目的是为了配置n台机器的免密码登录(通过密钥)

操作流程:

1.修改hosts，添加需要配置免密码登录的机器列表

2.用useradd.sh为n台机器创建用户 
  要求是,所有配置互信的机器的用户名必须相同
  sh useradd.sh username

3.运行new_trush.sh
./new_trush.sh home_of_username 
