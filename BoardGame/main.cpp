//
//  main.cpp
//  algo
//
//  Created by HJ Kim on 2018. 1. 8..
//  Copyright © 2018년 HJ Kim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>

int N;
int W,H;
char data;

int ** board;

int blocks[4][2][2] = {
    {{1,1},{0,1}}, //ㄱ
    {{1,0},{1,1}}, //ㄴ
    {{0,1},{1,1}}, // reverse ㄱ
    {{1,1},{1,0}} //reverse ㄴ
};

int solution();


int main() {
    
    scanf("%d",&N);
    
    while(N--){
        scanf("%d %d\n",&H,&W);
        
        //초기화
        board = (int**)malloc(sizeof(int*)*H);
        for(int i=0;i<H;i++){
            board[i] = (int*)malloc(sizeof(int)*W);
            memset(board[i], 0, sizeof(int)*W);
        }
        
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                scanf("%c",&data);
                if(data == '#'){
                    board[i][j] = 1;
                }else if(data == '.'){
                    board[i][j] = 0;
                }
            }
            if(i<H-1)
            scanf("\n");
        }
        
        printf("%d\n",solution());
        
        free(board);
    }
    
    return 0;
}

int solution(){
    
    int startPointX = -1;
    int startPointY = -1;
    
    int tmp=0;
    int tmpx=0;
    int tmpy=0;
    
    int ret = 0;
    
 
    
    //비어있는 좌표 찾기
    for(int i=0; i<H ; i++){
        for(int j=0; j<W; j++){
            if(board[i][j] == 0){
                startPointX = i;
                startPointY = j;
                goto Next;
            }
        }
    }
    
Next:
    
    if(startPointX == -1 && startPointY== -1){
        return 1; //경우의 수 1개 찾음
    }
    
    //블럭 놓기 4가지 경우
    //reverse ㄱ 은 주의!!
    for(int i=0;i<4;i++){
        
        tmp = 0;
        tmpx =0;
        tmpy =0;
        
        if(i==2){
            tmpy = -1;
        }
        
        //조건 맞는지 확인
        for(int p=0;p<2;p++) {
            for(int q=0;q<2;q++){
                
                if(( (startPointX+tmpx + p)  >= 0 && (startPointX+tmpx+p) < H)&&( (startPointY+q+tmpy) >= 0 && (startPointY+q+tmpy) <W)){
                    
                
                
                if(((blocks[i][p][q]==1&&board[startPointX+p+tmpx][startPointY+q+tmpy]==0) || blocks[i][p][q]==0)){
                    tmp++;
                }
                }
            }
        }
        
      

        if(tmp != 4){
            continue;
        }
        
      
            //block 놓기
            for(int p=0;p<2;p++) {
                for(int q=0;q<2;q++){
                        if(blocks[i][p][q]==1)
                        board[startPointX+p+tmpx][startPointY+q+tmpy] = blocks[i][p][q];
                   
                }
                //printf("\n");
            }
        
       
        
            ret += solution();
            
            //block 빼기
            for(int p=0;p<2;p++) {
                for(int q=0;q<2;q++){
                    if(blocks[i][p][q] == 1)
                        board[startPointX+p+tmpx][startPointY+q+tmpy] = 0;
                }
            }

        
    }
        
        
        return ret;
    }

