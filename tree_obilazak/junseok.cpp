#include<iostream>

using namespace std;
bool a[1100] = {false};
int A[1100];
int B[1100];
int C[1100];
int j=0;
void print(int i, int size){
	
		if(i<size){
			print((2*i)+1, size);	
			if(~a[i]){
				a[i] = true;
			//	cout<<i<<endl;
				B[j++] = i;
			}	
			print((2*i)+2, size);
		}
}
int main(){
	int k,i=0;
	cin>>k;

	int h=1;//height
	while(k--){
		h*=2;
	}h--;
	int height = h;
	while(h--){
		cin>>A[i++];	//�Է�
	}
	
	print(0,height);	//�迭 B �� inorder index ���� 

	int line = 1;
	for(i=0;i<height;i++){
		C[B[i]] = A[i];		//  C�� ����ġ
	}
	for(i=0;i<height;i++){
	
		if(line==i){
			for(int k=0;k<line;k++){
				cout<< C[i-1+k]<<" ";
			}cout<<endl;
			line +=i;
		}
	}
	
}