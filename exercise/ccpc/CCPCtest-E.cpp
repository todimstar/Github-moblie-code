/*E Epsilon Estuary
作者 Colin
单位 杭州电子科技大学
Recently Colin got addicted to playing a tactics puzzle RPG: Super Algebrawl. In the game, Colin transforms into a boar king with magical mathematical powers!  He is on a quest for glory, slaying the horrible monsters that plague the animal realm. Every encounter is a puzzle to be solved with logic and simple algebra! 
最近，科林沉迷于玩一款策略谜题角色扮演游戏：超级代数拉尔。在游戏中，科林变成了拥有魔法数学力量的猪王！他正在为荣耀而战，消灭困扰动物世界的可怕怪物。每一次遭遇都是一道需要用逻辑和简单的代数来解决的谜题！

Just now, Colin came to the next battlefield: Epsilon Estuary. The slimes are the rulers here, and they have a disgusting splitting skill - "SPLASH": once it is injured, assuming its remaining health is x, it will immediately split into two slimes with health ?x/2? and ?x/2? respectively, and the new slimes can continue to use this skill if they are injured in the future. A slime with health 0 will die immediately.
刚刚，科林来到了下一个战场：伊普西隆河口。这里的统治者是粘液生物，它们拥有令人恶心的分裂技能——"溅射"：一旦受伤，假设剩余生命值为 x ，它会立刻分裂成两个健康值分别为 ?x/2? 和 ?x/2? 的粘液生物，而新的粘液生物在未来如果受伤，仍可以继续使用这个技能。健康值为 0 的粘液生物会立即死亡。

However, our challenger Colin happens to have the best weapon against them: the “SHOCK” magic scroll! Specifically, every time Colin uses the shock magic scroll, it will inflict y damage to every monster. If a monster's health does not exceed y before Colin uses the magic scroll, it will die immediately after Colin uses the magic scroll.
然而，我们的挑战者科林恰好拥有对抗他们的最佳武器：“SHOCK”魔法卷轴！具体来说，每当科林使用 SHOCK 魔法卷轴，它会对每一个怪物造成 y 点伤害。如果怪物的血量在科林使用魔法卷轴之前不超过 y ，那么科林使用魔法卷轴后，怪物会立即死亡。

E.png

The image above shows an example: assuming y=5, and there are two slimes on the field with health values x 
1
?
 =25, x 
2
?
 =8. After Colin used the scroll once, their health became x 
1
′
?
 =20, x 
2
′
?
 =3 respectively. Then they split immediately. The first slime split into two slimes with health 10 and 10 respectively; the second slime split into two slimes with health 2 and 1 respectively.
上图显示了一个例子：假设 y=5 ，场上有两个血量为 x 
1
?
 =25, x 
2
?
 =8 的蠕虫。在 Colin 使用卷轴一次后，它们的血量分别变为 x 
1
′
?
 =20, x 
2
′
?
 =3 。然后它们立即分裂。第一个蠕虫分裂成两个血量分别为 10 和 10 的蠕虫；第二个蠕虫分裂成两个血量分别为 2 和 1 的蠕虫。

Colin's magic scroll can be used any number of times, so this is destined to be a one-way killing. But clicking the mouse repeatedly is too tiring, so Colin would like you to calculate, given the initial status of the slimes on the field, how many times does he need to use the scroll at least to ensure that all monsters on the field are killed?
科林的魔法卷轴可以无限次使用，所以这注定是一次单向的屠杀。但是连续点击鼠标太累人了，所以科林希望你能计算一下，给定战场上的粘液初始状态，他至少需要使用卷轴多少次才能确保战场上的所有怪物都被杀死？

Input
The first line contains a single integer T (1≤T≤10 
5
 ), representing the number of test cases.
第一行包含一个单独的整数 T (1≤T≤10 
5
 ) ，表示测试用例的数量。

For each test case: 对于每个测试案例：

The first line contains two integers n,y (1≤n≤10 
5
 ,1≤y≤10 
18
 ), representing the number of slimes on the battlefield and the damage can be made to each slime by using the magic scroll once.
第一行包含两个整数 n,y (1≤n≤10 
5
 ,1≤y≤10 
18
 ) ，表示战场上的粘液数量以及使用魔法卷轴一次所能造成的伤害。

The second line contains n integers x 
1
?
 ,x 
2
?
 ,…,x 
n
?
  (1≤x 
i
?
 ≤10 
18
 ), representing the initial health of each slime on the battlefield.
第二行包含 n 个整数 x 
1
?
 ,x 
2
?
 ,…,x 
n
?
  (1≤x 
i
?
 ≤10 
18
 ) ，表示战场上的每个粘液的初始生命值。

It’s guaranteed that the sum of n over all the test cases will not exceed 10 
6
 .
保证所有测试用例中 n 的总和不会超过 10 
6
  。

Output
Output T lines, the i-th line contains a single integer, representing the answer for the i-th test case.
输出 T 行，第 i 行包含一个整数，表示第 i 个测试用例的答案。

Sample Input
2
2 5
25 8
1 1
100
Sample Output
3
7
For the first test case, the changes in health of the slimes on the field are: {25,8}→{10,10,2,1}→{3,2,3,2}→?
对于第一个测试案例，场上粘液的健康变化为： {25,8}→{10,10,2,1}→{3,2,3,2}→? 

代码长度限制
16 KB
时间限制
1000 ms
内存限制
128 MB
栈限制
131072 KB*/
#include<iostream>
#include<vector>
#define LL long long

using namespace std;
LL y;

LL pd(LL m,LL sum){    //判断单个
    
    if(y>m){
        if(m>0)sum++;
        return sum;
    }
    LL  l,r;
    l=(m-y)/2;
    r=(m-y)-l;
    sum++;
    LL t1 = pd(l,sum);
    LL t2 = pd(r,sum);

    return  t1>t2?t1:t2;
}

int main (){

    int T,n;
    LL t,Tsum=0,sum;
    cin>>T;
    while(T--){
        Tsum=0;
        cin>>n>>y;
        vector<LL>m;
        
        for(int i=0;i<n;i++){
            cin>>t;
            m.push_back(t);
        }
        for(int i=0;i<n;i++){//遍历整个
            sum=pd(m[i],0);
            Tsum=sum>Tsum?sum:Tsum;
        }

        cout<<Tsum<<endl;
    }
    return 0;
}