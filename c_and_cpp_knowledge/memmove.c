#include<stdio.h>
#include<assert.h>

void *memmove(const void *src, void *des, size_t count){
	assert(src!=NULL || des!=NULL);
	assert(src!=des);
	char *tmp_src = (char*)src;
	char *tmp_des = (char*)des;
	if(tmp_des>tmp_src && tmp_des-tmp_src<count){
		tmp_des = tmp_des+count-1;
		tmp_src = tmp_src+count-1;
		while(count-- > 0){
			*tmp_des-- = *tmp_src--;
		}
	}
	else{
		while(count-- > 0){
			*tmp_des++ = *tmp_src++;
		}
	}
	return des;
}

int main(int argc, char *argv[]){

	return 0;
}
