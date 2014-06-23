#include<openssl/md5.h>
#include<cstring>
#include<iostream>
#include<iomanip>

int main(int argc,char*argv[]){
    MD5_CTX ctx;
    unsigned char md[17]={'\0'};
    // MD5_Init(&ctx);
    // MD5_Update(&ctx,data.c_str(),data.length());
    // MD5_Final(md,&ctx);

    MD5((const unsigned char*)(argv[1]),strlen(argv[1]),md);
    for(int i = 0; i < 16; i++) 
	std::cout << std::hex << (int)md[i];
    std::cout << std::endl;

    /* 每四个字节构成一个32位整数，
       将四个32位整数相加得到instr的hash值
       如果机器位数是32的话可能溢出*/
    size_t hash = 0;
    for(int i = 0; i < 4; i++)
	{
	    hash += ((size_t)(md[i*4 + 3]&0xFF) << 24)
		| ((size_t)(md[i*4 + 2]&0xFF) << 16)
		| ((size_t)(md[i*4 + 1]&0xFF) <<  8)
		| ((size_t)(md[i*4 + 0]&0xFF));
	}
    std::cout << std::dec << hash << std::endl;
    return 0;
}
