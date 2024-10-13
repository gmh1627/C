#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
#define lf double
const ll B=1<<28;

typedef struct{ll s[124],l;}Int;
Int p,q,r,s,t,y,z; int k,c; int n,pr[10005],o[100010];

int Max(int a,int b){return a>b?a:b;}

void Clear(ll *a,int l){int i; for (i=0; i<=l; i++) a[i]=0;}

void Copy(ll *a,ll *b,int l){int i; for (i=0; i<l; i++) a[i]=b[i];}

void Print(Int a){int i; for (printf("0x%llx",a.s[a.l]),i=a.l-1; i; i--) printf("%07llx",a.s[i]);}

int Cmp(Int a,Int b)
{
    if (a.l>b.l) return 1; if (a.l<b.l) return -1; int i;
    for (i=a.l; i; i--)
        if (a.s[i]>b.s[i]) return 1;
        else if (a.s[i]<b.s[i]) return -1;
    return 0;
}

Int Lsh(Int x,int k)
{
    if (k>=x.l) return Clear(x.s,x.l),x.l=1,x;
    return Copy(x.s+1,x.s+k+1,x.l-k),x.l-=k,Clear(x.s+x.l+1,k),x;
}

Int Add(Int a,Int b)
{
    a.l=Max(a.l,b.l); int i;
    for (i=1; i<=a.l; i++) a.s[i]+=b.s[i],a.s[i+1]+=a.s[i]/B,a.s[i]%=B;
    return a.l+=a.s[a.l+1]>0,a;
}

Int add(Int a,int b)
{
    a.s[1]+=b; int i;
    for (i=1; i<=a.l; i++) a.s[i+1]+=a.s[i]/B,a.s[i]%=B;
    return a.l+=a.s[a.l+1]>0,a;
}

Int Sub(Int a,Int b)
{
    a.l=Max(a.l,b.l); int i;
    for (i=1; i<=a.l; i++) if (a.s[i]-=b.s[i],a.s[i]<0) a.s[i]+=B,a.s[i+1]--;
    for ( ; !a.s[a.l]&&a.l>1; a.l--); return a;
}

Int Mul(Int a,Int b)
{
    Int E; Clear(E.s,123),E.l=a.l+b.l-1; int i,j;
    for (i=1; i<=a.l; i++) for (j=1; j<=b.l; j++)
        E.s[i+j-1]+=a.s[i]*b.s[j],E.s[i+j]+=E.s[i+j-1]/B,E.s[i+j-1]%=B;
    return E.l+=E.s[E.l+1]>0,E;
}

Int mul(Int a,int b)
{
    int i,x; for (i=1; i<=a.l; i++) a.s[i]*=b;
    for (i=1; i<=a.l; i++) a.s[i+1]+=a.s[i]/B,a.s[i]%=B;
    for (x=a.s[a.l+1]; x; x/=B) a.s[++a.l]=x%B;
    return a;
}

Int Div(Int a,Int b)
{
    Int E,c; int i,j,l,r,I;
    Clear(E.s,123),E.l=0,Clear(c.s,123),c.l=1;
    for (i=a.l; i; i--)
    {
        c=add(mul(c,B),a.s[i]);
        for (l=j=0,r=B-1; l<=r; )
        {
            if (I=l+r>>1,Cmp(mul(b,I+1),c)<1) l=I+1;
            else j=I,r=I-1;
        }
        if (E.s[++E.l]=j) c=Sub(c,mul(b,j));
    }
    for (i=1; i+i<=E.l; i++) j=E.s[i],E.s[i]=E.s[E.l-i+1],E.s[E.l-i+1]=j;
    for ( ; !E.s[E.l]&&E.l>1; E.l--); return E;
}

Int div2(Int a)
{
    int i; for (i=a.l; i; i--) a.s[i-1]+=a.s[i]%2*B,a.s[i]/=2;
    for ( ; !a.s[a.l]&&a.l>1; a.l--); return a;
}

Int Mod(Int a)
{
    Int E=Sub(a,Mul(Lsh(Mul(a,s),k),t));
    while (Cmp(E,t)>=0) E=Sub(E,t);
    return E;
}

int mod(Int a,int b)
{
    int i,c=0;
    for (i=a.l; i; i--) c=(c*B+a.s[i])%b;
    return c;
}

Int Pow(int x,Int b)
{
    Int a,E; int i,j; Clear(a.s,123),a.l=1,a.s[1]=x,Clear(E.s,123),E.l=E.s[1]=1;
    for (i=1,j=0; i<b.l||b.s[i]>=(1<<j); j=(j+1)%28,i+=!j)
    {
        if (b.s[i]>>j&1) E=Mod(Mul(E,a));
        a=Mod(Mul(a,a));
    }
    return E;
}

int MR(int p)
{
    Int a=Pow(p,y),b=a; int i; c++;
    for (i=0; i<2&&(a.l>1||a.s[1]>1); i++,a=b)
        if (b=Mod(Mul(b,b)),b.l<2&&b.l==1&&Cmp(a,z)) return 0;
	return a.l<2&&a.s[1]==1;
}

void BR(Int x){t=x,k=2*x.l,Clear(s.s,123),s.s[s.l=k+1]=1,s=Div(s,x);}

int Isp(Int x,int t)
{
    BR(y=x),y.s[1]--,z=y,y=div2(y); int i,p;
    for (i=1; i<=t; i++)
    {
        if (p=(ll)rand()*rand()%B/*rand()/4*rand()/32 rand()*/,p&1^1) p++;
        if (!MR(p)) return printf("Fail at test %d.\n",i),0;
    }
    return puts("Success!"),1;
}

Int Ranp()
{
    lf s=clock(); Int E; int i; c=0;
    while (1)
    {
        puts("Generating prime..."); lf t=clock();
        Clear(E.s,123),E.l=rand()%2+18;
        for (i=2; i<E.l; i++) E.s[i]=(ll)rand()*rand()%B;
        E.s[1]=(ll)rand()*rand()%(B/4)*4+3,E.s[E.l]=(ll)rand()*rand()%(B-1)+1;
        for (i=1; i<=n; i++) if (!mod(E,pr[i])){puts("Fail at pretest."); goto NG;}
        if (!Isp(E,10)) goto NG;
        printf("Total time cost %dms.\nAvg time cost %dms.\n",(int)(clock()-s+0.5),(int)((clock()-s)/c+0.5));
        return E; NG: printf("Time cost %dms.\n",(int)(clock()-t+0.5));
    }
}

int main()
{
    lf s=clock(),t; freopen("c1.txt","w",stdout);

    srand(time(0)); int i,j,k;
    for (i=2; i<100005; i++)
    {
        if (!o[i]) pr[++n]=i;
        for (j=1; j<=n&&(k=i*pr[j])<100005; j++) if (o[k]=1,i%pr[j]<1) break;
    }

    puts("prime p:"),p=Ranp(),puts("");
    puts("prime q:"),q=Ranp(),puts("");

    puts("blum:\nMultiplying..."),r=Mul(p,q);
    c=0,t=clock(),Isp(r,20);
    printf("Time cost %dms.\nAvg time cost %dms.\n\n",(int)(clock()-t+0.5),(int)((clock()-t)/c+0.5));

    printf("Total time cost %dms\n\n",(int)(clock()-s+0.5));
    printf("p: "),Print(p),puts("");
    printf("q: "),Print(q),puts("");
    printf("blum: "),Print(r),puts("");

    return 0;
}