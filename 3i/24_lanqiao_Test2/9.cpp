#include<iostream>

using namespace std;
// struct point{
//     int x,y;
// };
// struct LQ{
//     point a,b,c;
//     bool aa,bb,cc;
// };LQ q[26];
const int N =1e3+13;
char map[N][N];
int sum;

int main (){
    int n,m;
    cin>>n>>m;
    
    bool ax,bx,cx,au,bu,cu;
    int row,cl,rowx,clx,rowu,clu;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            au=bu=cu=ax=bx=cx = false;
            row=i;cl=j;
            rowx = clx = rowu = clu =0;
            //向下
            while(map[row][cl] == map[row+1][cl]){//row行向下
                row++;
                ax = true;
            }rowx = row;clx = cl;//记录下行点
            while(ax && row>0 && cl>0 && map[row-1][cl-1] == map[row][cl]){
                row--;
                cl--;
                bx = true;
            }
            while(bx && cl < m && map[row][cl+1] == map[row][cl]){
                cl++;
                cx = true;
            }if(cx && bx && ax && row == i && cl == j){//左下绕一圈
                sum++;
            }
            //右下
            bx=cx=false;
            while(ax && rowx>0 && clx<m && map[rowx-1][clx+1] == map[rowx][clx]){
                rowx--;
                clx++;
                bx =true;
            }
            while(bx && clx > 0 && map[rowx][clx-1] == map[rowx][clx]){
                clx--;
                cx = true;
            }if(cx && bx && ax && rowx == i && clx == j){//右下绕一圈
                sum++;
            }
            //向上
            row=i;cl=j;
            while(map[row][cl] == map[row-1][cl]){
                row--;
                au = true;
            }rowu = row;clu = cl;//记录上行点
            while(au && row<n && cl>0 && map[row+1][cl-1] == map[row][cl]){
                row++;
                cl--;
                bu = true;
            }
            while(bu && cl < m && map[row][cl+1] == map[row][cl]){
                cl++;
                cu = true;
            }if(cu && bu && au && row == i && cl == j){//左下绕一圈
                sum++;
            }
            //右上
            bu=cu=false;
            while(au && rowu<n && clu<m && map[rowu+1][clu+1] == map[rowu][clu]){
                rowu++;
                clu++;
                bu =true;
            }
            while(bu && clu > 0 && map[rowu][clu-1] == map[rowu][clu]){
                clu--;
                cu = true;
            }if(cu && bu && au && rowu == i && clu == j){//右下绕一圈
                sum++;
            }
        }
    }
    cout<<sum;
    
    return 0;
}