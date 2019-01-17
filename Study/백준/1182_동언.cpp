#include <iostream>
#include <cstdio>

using namespace std;

int ans;
int set[30];
int _arr[30];
void subset(int arr[],int size, int n, int index, int s){
	if(n == index){
		int sum=0;
		for(int i=0;i<size;i++){
			sum+=set[arr[i]];
		}
		if(sum == s && size !=0){		
			ans++;
		}
		return;
	}
	arr[size] = index;
	subset(arr,size+1,n,index+1,s);
	subset(arr,size,n,index+1,s);
}
int main() {
	// your code goes here
	int N,S;
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&set[i]);
	}
	subset(_arr,0,N,0,S);
	cout<<ans;
	return 0;
}