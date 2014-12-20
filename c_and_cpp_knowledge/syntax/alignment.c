
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct test{
	unsigned is_keyword: 11;
	unsigned is_extern : 11;
	unsigned is_static : 11;
};

int main(int argc, char* argv[]){
	printf("%d\n",sizeof(struct test));	
	return 0;
}
