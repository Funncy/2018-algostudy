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
#include <set>

using namespace std;

int order(const vector<int>& russian, const vector<int>& korean);

int N;
int caseN;

vector<int> russian;
vector<int> korean;

int main(){
    
    scanf("%d",&N);
    int tmp=0;
    
    while(N--){
        
        scanf("%d",&caseN);
        
        for(int i=0;i<caseN;i++){
            scanf("%d",&tmp);
            russian.push_back(tmp);
        }
        for(int i=0;i<caseN;i++){
            scanf("%d",&tmp);
            korean.push_back(tmp);
        }
        
        printf("%d\n",order(russian,korean));
    
        korean.clear();
        russian.clear();
    }
    
    return 0;
}

int order(const vector<int>& russian, const vector<int>& korean){
    int n = russian.size();
    int wins = 0;
    
    multiset<int> ratings(korean.begin(), korean.end());
    
    for(int rus = 0; rus < n; ++rus){
        if(*ratings.rbegin() < russian[rus])
            ratings.erase(ratings.begin());
        else{
            ratings.erase(ratings.lower_bound(russian[rus]));
            ++wins;
        }
    }
    
    return wins;
    
}
