

void swap(int * a ,int * b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

typedef struct{
  int lo;int hi;
}stack_node;
  
#define MAX_THRESH 4
#define STACK_SIZE      (8 * sizeof(size_t))
#define PUSH(low, high) (((top->lo = (low)), (top->hi = (high)), ++top))
#define POP(low, high)  ((--top, (low = top->lo), (high = top->hi)))
#define STACK_NOT_EMPTY (stack < top)

int median_of_three(int a[],int l,int r){
  int mid = (l+r) / 2;
  if(a[mid]<a[l])
    swap(&(a[mid]),&(a[l]));
  if(a[r]<a[mid])
    swap(&(a[mid]),&(a[r]));
  else return mid;
  if(a[mid]<a[l])
    swap(&(a[mid]),&(a[l]));
  return mid;
}

int partition(int a[],int l,int r){
  int mid = median_of_three(a,l,r);
  swap(&(a[mid]),&(a[r-1]));
  int key = a[r-1];
  int i=l+1;
  int j=r-1;
  while(i<j){
    while(i<j && a[i]<=key) i++;
    a[j]=a[i];
    while(i<j && a[j]>=key) j--;
    a[i]=a[j];
  }
  a[j]=key;
  return j;
}

void quicksort(int a[],int l,int r){
  if(r-l>MAX_THRESH){
    stack_node stack[STACK_SIZE];
    stack_node* top = stack;
    PUSH(0,0);
    int low = l;
    int high = r;

    while(STACK_NOT_EMPTY){

      int mid = (low+high) / 2;
      if(a[mid]<a[low])
	swap(&(a[mid]),&(a[low]));
      if(a[high]<a[mid])
	swap(&(a[mid]),&(a[high]));
      else goto jump_over;
      if(a[mid]<a[low])
	swap(&(a[mid]),&(a[low]));

    jump_over:;

      swap(&(a[mid]),&(a[high-1]));
      int key = a[high-1];
      int i=low+1;
      int j=high-1;
      while(i<j){
	while(i<j && a[i]<=key) i++;
	a[j]=a[i];
	while(i<j && a[j]>=key) j--;
	a[i]=a[j];
      }
      a[j]=key;

      int pivot = j;
      if(pivot - low <= MAX_THRESH){
      	if(high - pivot<=MAX_THRESH)
      	  POP(low,high);
      	else low = pivot + 1;
      }
      else if(high - pivot<=MAX_THRESH){
        high = pivot - 1;
      }
      else if((pivot - low)>(high - pivot)){
      	PUSH(low,pivot-1);
      	low = pivot+1;
      }
      else{
      	PUSH(pivot+1,high);
      	high = pivot - 1;
      }
    }
  }


#define min(x,y) ((x) < (y) ? (x) : (y))
  {//插入排序
    int i=l,j=l,k=l;
    int tmp = 0;
    int thresh = min(MAX_THRESH,r-l+1);
    for(i=l+1;i<l+thresh;i++)
      if(a[i] < a[j])
	j = i;
    swap(&(a[l]),&(a[j]));
    for(i=l+2;i<=r;i++){
      for(j=i-1;a[i]<a[j];j--);
      j += 1;
      tmp = a[i];
      for(k=i;k>j;k--)
	a[k] = a[k-1];
      a[k]=tmp;
    }
  }

}

