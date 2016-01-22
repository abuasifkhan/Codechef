//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: A Asif Khan Chowdhury
/** ========================================**/

#include <bits/stdc++.h>

using namespace std;

#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pii pair <ll, ll>
#define pb push_back
#define open freopen("D:/a.txt", "r", stdin);
#define write freopen("D:/b.txt","w", stdout);
#define inf (1ll<<28)
#define ll long long
#define mod 1000000007
#define gc getchar
#define ls(n) (n<<1)
#define rs(n) ls(n)|1
#define MID(a,b) ((a+b)>>1)
#define fs first
#define sc second
#define mx 100010

template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
int X[]= {-1, -1, -1, 0, 1, 1, 1, 0};   //x 8 direction
//int Y[]= {-1, 0, +1, 1, 1, 0, -1, -1};  //y 8 direction
// int X[]= {-1, 0, 1, 0};   //x 4 direction
// int Y[]= { 0, 1, 0, -1};  //y 4 direction

ll s, r,c;
ll grid[160][160];
ll tree[160];
ll Z[160];
pii Y[160];

void update(int idx,ll v){
    while(idx<160){
        tree[idx]+=v;
        idx+=(idx&-idx);
    }
}
ll query (int idx){
    ll ret=0;
    while(idx){
        ret+=tree[idx];
        idx-=(idx&-idx);
    }
    return ret;
}


ll solve(){
    ll ans = 0;
    for(int i=1;i<=c;i++){
        for(int j=i;j<=c;j++){
            Y[0]=pii(0ll,0ll);
            for(int k=1;k<=r;k++){
                Y[k] = pii(Y[k-1].fs+grid[k][j]-grid[k][i-1],k);
            }
            sort(Y,Y+r+1);
//            for(int k=0;k<=r;k++)cout<<Y[k].fs<<" ";cout<<endl;
            for(int i=0;i<160;i++)tree[i]=0;
            int t = 0;
            ll tans=0;
            for(int k=0;k<=r;k++){
                while( Y[k].fs-Y[t].fs>s){
                    update(Y[t++].sc+1,1);
                }
                tans += query(Y[k].sc+1);
            }
            ans += r*(r+1)/2 - tans;
        }
    }
    return ans;
}

int main() {
    #ifdef LOCAL
    freopen("D:/a.txt", "r", stdin);
    #endif // LOCAL

    int test;
    read(test);
    for(int C=1;C<=test;C++) {
        read(r);read(c);read(s);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                read(grid[i][j]);
                grid[i][j]+=grid[i][j-1];
            }
        }
//        for(int i=1;i<=r;i++){
//            for(int j=1;j<=c;j++){
//                cout<<grid[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        ll ans = solve();
        printf("%lld\n",ans);
    }

    return 0;
}




