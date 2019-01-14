//
//  main.cpp
//  1018
//
//  Created by 유승아 on 10/01/2019.
//  Copyright © 2019 Seungah Yoo. All rights reserved.
//

#include <iostream>

int m,n;
char map[51][51]={0,};
char mmap[51][51]={0,};

int dy[2]={-1,0};
int dx[2]={0,-1};//위, 왼쪽

void map_copy(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mmap[i][j] = map[i][j];
        }
    }
}

int make_chess(int start_y, int end_y, int start_x, int end_x){
    int change=0;
    map_copy();
    
    for(int i=start_y; i<=end_y;i++){
        for(int j=start_x; j<=end_x; j++){
           // now = mmap[i][j];
            
            for(int k=0;k<2;k++){
                int ny = i+dy[k];
                int nx = j+dx[k];
                
                if(ny<start_y || nx <start_x || ny>end_y || nx>end_x) continue;
                
                if(mmap[i][j] == mmap[ny][nx]){
                    mmap[i][j] = (mmap[i][j]=='W')? 'B':'W';
                    change++;
                }
                
            }
            
            
        }
    }
    
    return change;
}



int main(int argc, const char * argv[]) {
    
    scanf("%d %d", &m,&n);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&map[i][j]);
            //if(c=='\n')
        }
    }
    
    int min = 987654321;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int end_y = i+7;
            int end_x = j+7;
            if(end_y<m && end_x<n){
                int ret = make_chess(i,end_y,j,end_x);
                ret = ret > (64-ret)? 64-ret : ret;
                min = min > ret? ret : min;
            }
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}
