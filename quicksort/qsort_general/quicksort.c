
#include<limits.h>
#include<string.h>

typedef struct{
  char* lo; char* hi;
}stack_node;

#define MAX_THRESH 5
#define STACK_SIZE	(CHAR_BIT * sizeof(size_t))
#define PUSH(low, high)	(((top->lo = (low)), (top->hi = (high)), ++top))
#define	POP(low, high)	((--top, (low = top->lo), (high = top->hi)))
#define	STACK_NOT_EMPTY	(stack < top)

typedef int (*__compar_fn_t) (const void* ,const void* ); 

inline void swap(char* __a,char* __b,size_t size){
  while(size-- > 0){
    char __temp = *__a;
    *__a++ = *__b;
    *__b++ = __temp;
  }
}

void quicksort(arr,total_elems,size,cmp)
     void*const arr;
     size_t total_elems;
     size_t size;
     __compar_fn_t cmp;
{
  const size_t max_thresh = size*MAX_THRESH;
  stack_node stack[STACK_SIZE];
  stack_node* top = stack;
  PUSH(NULL,NULL);
  char* base_ptr = (char*) arr;
  char* low = base_ptr;
  char* high = &low[size*(total_elems-1)];

  if(total_elems>MAX_THRESH){
    while(STACK_NOT_EMPTY){

      //median_of_three
      char* mid = low + size*((high-low)/size>>1);
      if((*cmp)((void*)mid,(void*)low) < 0)
	swap(mid,low,size);
      if((*cmp)((void*)high,(void*)mid) <0 )
	swap(high,mid,size);
      else 
	goto jump_over;
      if((*cmp)((void*)mid,(void*)low) < 0)
	swap(mid,low,size);

    jump_over:;
      //partition
      char key[size];
      strncpy(key,mid,size);
      swap(low+size,mid,size);
      char* left_ptr=low+2*size;
      char* right_ptr=high-size;
      while(left_ptr<=right_ptr){
	while(left_ptr<=right_ptr && 
	      (*cmp)((void*)left_ptr,(void*)key) <= 0 )
	  left_ptr += size;
	while(left_ptr<=right_ptr &&
	      (*cmp)((void*)key,(void*)right_ptr) <=0 )
	  right_ptr -= size;
	if(left_ptr<right_ptr){
	  swap(left_ptr,right_ptr,size);
	  left_ptr += size;
	  right_ptr -= size;
	}
	else if(left_ptr == right_ptr){
	  left_ptr += size;
	  right_ptr -= size;
	}
      }
      swap(left_ptr-size,low+size,size);

      char* q = left_ptr-size;

      if(q-low<=max_thresh){
	if(high-q<=max_thresh)
	  POP(low,high);
	else low = q+size;
      }
      else if(high-q<=max_thresh){
	high = q-size;
      }
      else if((q-low)>(high-q)){
	PUSH(low,q-size);
	low = q+size;
      }
      else{
	PUSH(q+size,high);
	high = q-size;
      }
    }
  }

  {
    /*插入排序模块*/
    char* i = base_ptr,*j;
    char* end_ptr = &base_ptr[size*(total_elems-1)];
    for(i=base_ptr;i<end_ptr;i += size)
      for(j=i+size;j>base_ptr;j -= size)
  	if((*cmp)((void*)j,(void*)(j-size)) < 0)
  	  swap(j,j-size,size);
  }
}

