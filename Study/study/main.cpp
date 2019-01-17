#include <iostream>
using namespace std;

int arr[] = {0,1,2,3,4};
int arrSize =3;
int m=2; //m개를 골라라
int ans[5];

void print(){
 
    for(int i=0;i<m;i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}


void Combination(int len, int k){ //조합 1
    if(len == m){ //종료 조건
        print();
        return;
    }
    
    for(int i=k;i<arrSize;i++){
        ans[len] = i;
        Combination(len+1, i+1);
    }
}

void Combination2(int len, int k){ //조합 2
    if(len == m){ //종료 조건
        print();
        return;
    }
    if(arrSize == k) return;
    
    ans[len] = k;
    Combination2(len+1, k+1);
    Combination2(len,k+1);
}

void R_Combination(int len, int k){ //중복조합
    if(len == m){ //종료조건
        //len은 내가 현재 선택한 숫자의 갯수
        //m개의 숫자를 골랐다면 종료해라
        print();
        return;
    }
    if(arrSize == k) return;
    //또는, 내가 선택하려는 숫자가 인덱스 범위를 넘어가면 종료해라.
    
    ans[len] = k;
    
    R_Combination(len+1,k); //다음 인덱스에 현재 숫자부터
    R_Combination(len,k+1); //현재 인덱스에 다음 숫자부터
}

void swap(int i, int len){
    int tmp = arr[i];
    arr[i] = arr[len];
    arr[len] = tmp;
}

void Permutation(int len){
    if(len == m){
        for(int j=0;j<len;j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
        return;
    }
    for(int i=len;i<arrSize;i++){
        swap(i,len);
        Permutation(len+1);
        swap(i,len);
    }
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

void subset(int len, int k){//부분집합 구하기
    
    if(arrSize==k){//종료조건
        for(int i=0;i<len;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    
    ans[len] = k;
    subset(len+1, k+1);
    subset(len,k+1);
}


int main(int argc, const char * argv[]) {
    
    //Combination(0,0);
    printf("\n");
    //Combination2(0, 0);
    //R_Combination(0,0);
    //Permutation(0);
    subset(0,0);
    
    return 0;
}
