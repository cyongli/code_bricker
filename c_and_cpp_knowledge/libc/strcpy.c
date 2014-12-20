#include<stdio.h>
#include<assert.h>

char *strcpy(const char *src, char *des){
	assert(src!=NULL || des!=NULL);
	assert(src!=des);
	char *address = des;
	while((*des++ = *src++)!='\0');
	return address;
}

int main(int argc, char *argv[]){

	return 0;
}
