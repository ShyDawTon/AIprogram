#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool path[2003][2003];

int main()
{
    int N,M;
    while(cin>>N>>M, N!=0, M!=0){
        memset(path, false, 2003*2003);
        // 前置輸入處理
        for(int i=0; i<M; i++){
            int V,W,P;
            cin>>V>>W>>P;
            if(P==1)
                path[V][W]=true;
            else{
                path[V][W]=true;
                path[W][V]=true;
            }
        }


        // 做path的填入
        for(int k=1; k<=N; k++){
            for(int i=1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    path[i][j] |= path[i][k] && path[k][j];
                    printf("i=%d    k=%d    j=%d    V[%d][%d]=%d\n", i, k, j, i, j, path[i][j]);
                }
            }
        }

        // 做強連結判斷
        bool strong=true;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                //printf("%d %d %d\n", i, j, path[i][j]);
                if(i!=j && !path[i][j]){
                    strong=false;
                    break;
                }
            }
        }

        printf("%d\n", strong);
    }
}



modify test --105127