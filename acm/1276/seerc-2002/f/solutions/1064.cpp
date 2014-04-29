//* Problem  : SEERC-2002-F
//* Date     : 2008.11.11
//* Author   : alt

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

// to disable Visual C++ secure warnings
#pragma warning(disable : 4996)

///BEGIN CUT HERE
// types
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int,int> PII;
typedef vector <int> VI;
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
#define FORSZR(i, a) FORR(SZ(a), i)
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
const double PI = acos(-1.0);
const double EPS = 1E-9;

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
inline void pvi(VI a){FORSZ(i,a) printf("%d%c", a[i], i == a.size() - 1 ? '\n' : ' ');}
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
///END CUT HERE

int r[100010], rem;

void solve()
{
}

void result()
{
}

int main()
{
#ifdef _DEBUG
	freopen("1064", "r", stdin);
	freopen("1064o", "w", stdout);
#endif
	int mx;
	int nt = 0;
	while (scanf("%d", &mx) == 1)
	{
		if (nt) putchar('\n'); nt++;
		int policy = 1;
		priority_queue <int, vector<int>, greater<int> > qmin;
		priority_queue <int, vector<int>, less<int> > qmax;
		VI rmin(mx + 1, 0);
		VI rmax(mx + 1, 0);
		CLA(r);
		REP(ri()) r[ri()] = 1;
		rem = 0;
		while (1)
		{
			char c = 0;
			while (c != 'a' && c != 'e' && c != 'p' && c != 'r') c = getchar();
			// end
			if (c == 'e')
			{				
				break;
			}
			// policy
			if (c == 'p') policy = ri();
			if (c == 'a')
			{
				int val = ri();
				qmin.push(val);
				qmax.push(val);
			}
			if (c == 'r')
			{
				VI &v = (policy == 1 ? rmin : rmax);
				rem++;
				if (policy == 1)
				{
					while (!qmin.empty() && v[qmin.top()]) v[qmin.top()]--, qmin.pop();
					if (qmin.empty()) pi(-1);
					else
					{
						int v = qmin.top(); qmin.pop();
						if (r[rem]) pi(v);
						rmax[v]++;
					}
				}
				else
				{
					while (!qmax.empty() && v[qmax.top()]) v[qmax.top()]--, qmax.pop();
					if (qmax.empty()) pi(-1);
					else
					{
						int v = qmax.top(); qmax.pop();
						if (r[rem]) pi(v);
						rmin[v]++;
					}
				}
			}

			
		}
	}
	return 0;
}

