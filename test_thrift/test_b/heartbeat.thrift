struct heartbeat{
       1:string hostname,
       2:double cpu_util,
       3:double mem_util,
       4:double disk_util
}

service trans_heartbeat{
	void trans_heartbeat(1:heartbeat hb);
}