#include <iostream>
using namespace std;

int arr[] = {0,1,2,3,4};
int arrSize =5;
int m=2; //m개를 골라라
int ans[5];

void print(){
 
    for(int i=0;i<m;i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}

void Combination(int len, int k){ //조합
    if(len == m){ //종료 조건
        print();
        return;
    }
    
    for(int i=k;i<arrSize;i++){
        ans[len] = i;
        Combination(len+1, i+1);
    }
}

void Combination2(int len, int k){
    if(len == m){ //종료 조건
        print();
        return;
    }
    
    arr[len] = k;
    Combination2(len+1, k-1);
}

void R_Combination(){
    
}

void R_Permutation(int len){//중복순열
    if(len == m){ //종료 조건
        
        print();
        return;
    }
    
    for(int i=0;i<arrSize;i++){
        ans[len] = arr[i];
        R_Permutation(len+1);
    }
}




int main(int argc, const char * argv[]) {
    
    Combination(0,0);
    printf("\n");
    //R_Combination(0);
    
    return 0;
}
