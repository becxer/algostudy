#include <stdio.h>
int mountain(int num){
	if(num ==1) return 1;
	return mountain(num--);
}
int main(){
	int n;
	scanf("%d",&n);
	mountain(n);
}

 // 1�϶�   1 
 // 2�϶�   1+2+1 
 // 3�϶��� 2+3+2
 // 4�϶��� 3+4+3 
 // 5�ϋ��� 4+5+4