#include <iostream>
#include <vector>

using namespace std;

/*
void SetOne(vector < vector<char> >&grid,int row,int col){
    int m = grid.size();
    int n = grid[0].size();
    if((row <0) || (row)>= m || (col<0) || (col>=n) || (grid[row][col] != '1')){
        return;
    }
    grid[row][col] = 2;
    SetOne(grid,row + 1,col);
    SetOne(grid,row - 1,col);
    SetOne(grid,row,col +1);
    SetOne(grid,row,col -1);
}

int numIslands(vector< vector<char> >& grid)
{
    int m = grid.size();
    if(0 == m)return 0;
    int n = grid[0].size();
    if(0 == n)return 0;
    int sum = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if('1' == grid[i][j]){
                ++sum;
                SetOne(grid,i,j);
            }
        }
    }
    return sum;
}
*/
int getF(vector<int> &father, int v){
    if(father[v] == v) return v;
    else{
        //Ñ¹ËõÂ·¾¶
        father[v] = getF(father,father[v]);
        return father[v];
    }
}

void Merge(vector<int> &father,int v,int u){
    int t1 = getF(father,v);
    int t2 = getF(father,u);
    if(t1 != t2){
        father[t2] = t1;
    }
}

int numIslands(vector< vector<char> >& grid){
    int n = grid.size();
    if(0 == n)return 0;
    int m = grid[0].size();
    if(0 == m)return 0;
    int k = n*m;
    vector<int> father(k,-1);

    for(int i=0;i<k;i++){
        father[i] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t1 = i*m +j;
            int t2 = t1 +1;
            int t3 = t1 + m;
            if(j+1<m && grid[i][j] == grid[i][j+1])Merge(father,t1,t2);
            if(i+1<n && grid[i][j] == grid[i+1][j])Merge(father,t1,t3);
        }
    }
    int sum = 0;
    for(int i=0;i<k;i++){
        if(father[i] == i && grid[i/m][i%m] == '1'){
            ++sum;
        }
    }
    return sum;
}

int main()
{
    return 0;
}
