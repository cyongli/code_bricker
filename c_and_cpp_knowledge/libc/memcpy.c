#include<stdio.h>
#include<assert.h>

void *memcpy(const void *src, void *des, size_t count){
	assert(src!=NULL || des!=NULL);
	assert(src!=des);
	char *tmp_des = (char*)des;
	char *tmp_src = (char*)src;
	while(count-- > 0){
		*tmp_des = *tmp_src++;
	}
	return des;
}


int main(int argc, char *argv[]){
	
	return 0;
}
