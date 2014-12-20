//* Problem  : 
//* Date     : 2009.08.02
//* Author   : alt
//* Tags     : 

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <string>
#include <vector>
#include <cctype>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

//stack
//#pragma comment(linker, "/STACK:16777216")

// to disable Visual C++ secure warnings
#pragma warning(disable : 4996)

///BEGIN CUT HERE
// types
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int,int> PII;
//typedef vector <int> VI;
typedef vector <int64> VI64;
typedef vector <string> VS;
typedef vector <vector<string> > VVS;
typedef vector <vector<int> > VVI;
typedef vector <pair<int,int> > VPII;
typedef vector <vector<pair<int,int> > > VVPII;
typedef map<int, int > MII;
typedef map<string, int > MSI;
typedef queue<int > QI;
typedef queue<PII > QPII;
//loops
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define FORR(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define FORE(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FORER(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define FORSZ(i, a) FOR(i, SZ(a))
#define FORSZR(i, a) FORR(i, SZ(a))
#define FORO(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define FOROR(i, x) for (typeof((x).end()) i = (x).end(); i != (x).begin(); i--)
#define REP(n) for (int _foo = (int)(n) - 1; _foo >= 0; _foo--)
#define REP2(n) for (int _foo2 = (int)(n) - 1; _foo2 >= 0; _foo2--)

#define VAR(a, b) typeof(b) a=(b)
#define FOREACH(it, c) for(VAR(it,(c).begin()); it!=(c).end(); it++)
//sorting & c
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define RSORT(a) sort(RALL(a))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define REVERSE(a) reverse(ALL(a))
//filling
#define FLA(a,val) memset(a, val, sizeof(a))
#define FLO(o,val) memset(&o, val, sizeof(o))
#define CLA(a) FLA(a, 0)
#define CLO(a) FLO(a, 0)
//misc
#define _x first
#define _y second
#define MP make_pair
#define PB push_back
#define SZ(a) (int)a.size()
#define POP(a) a.top(), a.pop()
#define FRONT(a) a.front(), a.pop()
//const
const int INF = 1000000000;
const int64 INFL = 1000000000000000000LL;
const long double PI = acos(-1.0);
const long double EPS = 1E-9;

const int dx8[] = {-1, 1, 0, 0, -1, -1,  1, 1};
const int dy8[] = {0, 0, -1, 1, -1,   1, -1, 1};

//some math
template <typename T> inline T gcd(T a, T b)				{ return b ? gcd(b, a % b) : a; }
template <typename T> inline T gcd2(T a, T b)				{ while (a && b) (a > b) ? a %= b : b %= a; return a + b;}
template <typename T> inline T lcm(T a, T b)				{ return a / gcd(a, b) * b; }
template <typename T> inline T abs(T a)					{ return a < 0 ? -a : a; }
template <typename T> inline T sqr(T a)					{ return a * a; }
template <typename T> inline double hypot(T a, T b)		{ return sqrt(1.0 * a * a + b * b);}
//template <typename T> inline double hypot(T a, T b, T ñ)	{ return sqrt(1.0 * a * a + b * b + ñ * ñ);}
template <typename T> inline T hypot2(T a, T b)			{ return a * a + b * b;}
//template <typename T> inline T hypot2(T a, T b, T c)		{ return a * a + b * b + c * c;}
template <typename T> inline void chMin(T& a, T b) { if (b < a) a = b; }
template <typename T> inline void chMax(T& a, T b) { if (b > a) a = b; }

//assertions
#ifdef _DEBUG
#define ASSERT(f) if (!(f)) printf("%s\n", "ASSERTION FAILED!");
#define ASSERTS(f, s) if (!(f)) printf("%s [%s]\n", "ASSERTION FAILED!", s);
#else
#define ASSERT(f) f
#define ASSERTS(f, s) f
#endif

int cmp_int(const void *a, const void *b){return *(int*)a - *(int*)b;}
int cmp_double(const void *a, const void *b){double t = *(double*)a - *(double*)b;return (fabs(t) < EPS) ? 0 : t > 0 ? 1 : -1;}
int cmp_int64(const void *a, const void *b){int64 t = *(int64*)a - *(int64*)b; return !t ? 0 : t > 0 ? 1 : -1;}

//input
inline void ri(int &tt){ASSERTS(scanf("%d", &tt) == 1, "ReadInt failed");}
inline int ri(){int tt; ASSERTS(scanf("%d", &tt) == 1, "ReadInt failed"); return tt;}
inline void ri64(int64 &tt){ASSERTS(scanf("%lld", &tt) == 1, "ReadInt64 failed");}
inline int64 ri64(){int64 tt; ASSERTS(scanf("%lld", &tt) == 1, "ReadInt64 failed"); return tt;}
inline void rd(double &tt){ASSERTS(scanf("%lf", &tt) == 1, "ReadDouble failed"); }
inline double rd(){double tt; ASSERTS(scanf("%lf", &tt) == 1, "ReadDouble failed"); return tt;}
inline void rs(char *s){ASSERTS(scanf("%s", s) == 1, "ReadChar* failed");}
//output
inline void pvi(int *a, int n){FOR(i, n) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');}
//inline void pvi(VI a){FORSZ(i,a) printf("%d%c", a[i], i == a.size() - 1 ? '\n' : ' ');}
inline void pi(int n){printf("%d\n", n);}
inline void pi64(int64 n){printf("%lld\n", n);}

inline void _pi64(int64 n)
{
	if (n < 0) {putchar('-'); n = -n;}
	if (!n) {putchar('0'); return;}
	char stack[30]; int istack = 0;
	while (n)
	{
		stack[istack++] = (n % 10) + '0'; n /= 10;
	}
	while (istack > 0)
		putchar(stack[--istack]);
}
const int dx4[] = {-1, 1, 0, 0};
const int dy4[] = {0, 0, -1, 1};
///END CUT HERE

struct mypoint{
	double x, y;
}a[1500];

struct myline{
	double a, b, c;
};

int n;

double res;

int eq(double a, double b)
{
	return fabs(a - b) < EPS;
}

void to_line(mypoint &p1, mypoint &p2, myline &l)
{
	if (eq(p1.x, p2.x))
	{
		l.a = 1;
		l.b = 0;
		l.c = -p1.x;
	}
	else
	{
		l.a = - (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1;
		l.c = - (l.a * p1.x + l.b * p1.y);
	}
}

double det(double a, double b, double c, double d)
{
	return a * d - b * c;
}

int inters(myline a, myline b, mypoint &r)
{
	double den = det(a.a, a.b, b.a, b.b);
	if (fabs(den) < EPS)
		return 0;
	r.x = -det(a.c, a.b, b.c, b.b) / den;
	r.y = -det(a.a, a.c, b.a, b.c) / den;
	return 1;
}

double triangle_sq(mypoint &a, mypoint &b, mypoint &c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int cmp(mypoint a, mypoint b)
{
	if (!eq(a.x, b.x))
		return a.x < b.x;
	return a.y < b.y;
}

int cw(mypoint a, mypoint b, mypoint c)
{
	return triangle_sq(a, b, c) < -EPS;
}

int ccw(mypoint a, mypoint b, mypoint c)
{
	return triangle_sq(a, b, c) > EPS;
}


void convex_hull(vector<mypoint> &a)
{
	sort(ALL(a), cmp);
	int n = SZ(a);
	mypoint &left = a.front(), &right = a.back();
	vector <mypoint> up, down;
	up.PB(left); down.PB(left);
	FOR(i,n)
	{
		if (i == n - 1 || cw(left, a[i], right))
		{
			while (SZ(up) >= 2 && !cw(up[SZ(up)-2], up[SZ(up)-1], a[i]))
			{
				up.pop_back();
			}
			up.PB(a[i]);
		}
		if (i == n - 1 || ccw(left, a[i], right))
		{
			while (SZ(down) >= 2 && !ccw(down[SZ(down)-2], down[SZ(down)-1], a[i]))
			{
				down.pop_back();
			}
			down.PB(a[i]);
		}
	}
	a.clear();
	a.assign(ALL(up));
	FORER(i, SZ(down) - 2, 1)
		a.PB(down[i]);
}

	
int check(mypoint &p)
{
	double sign = 0;
	FOR(i,n)
	{
		double t = triangle_sq(a[i], p, a[i+1]);
		if (fabs(t) > EPS)
		{
			sign = t; break;
		}
	}
	FOR(i,n)
	{
		double t = triangle_sq(a[i], p, a[i+1]);
		if (t * sign < -EPS)
			return 0;
	}
	return 1;
}

mypoint b[1500 * 1500], pc;

int k;

vector<mypoint> aa;

void solve()
{
	k = 0;
	pc.x = pc.y = 0;
	FOR(i,n) FOR(j,n)
	{
		if (i + j == 1)
		{
			i/=1;
		}
		myline l1, l2;
		mypoint p;
		to_line(a[i], a[i+1], l1);
		to_line(a[j], a[j+1], l2);
		if (inters(l1, l2, p))
		{
			//printf("%lf %lf\n", p.x, p.y);
			if (check(p))
			{
				b[k++] = p;
				pc.x += p.x;
				pc.y += p.y;
				//return;
			}
		}
	}
	pc.x /= k;
	pc.y /= k;
	aa.clear();
	FOR(i, k)
		aa.PB(b[i]);

	convex_hull(aa);

	res = 0;
	k = SZ(aa);
	aa.PB(aa[0]);
	FOR(i, k)
		res += (aa[i+1].x - aa[i].x) * (aa[i].y + aa[i+1].y);
	res = abs(res) / 2.0;
}


int main()
{
#ifdef _DEBUG
	freopen("1064", "r", stdin);
	//freopen("1064o", "w", stdout);
#endif
	REP(ri())
	{
		n = ri();
		FOR(i,n)
			a[i].x = ri(),
			a[i].y = ri();
		a[n] = a[0];
		solve();
		//puts(res ? "YES" : "NO");
		printf("%.2lf\n", res);
	}
}


