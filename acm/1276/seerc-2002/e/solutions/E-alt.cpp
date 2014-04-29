//* Problem  : SEERC-2002-E (DP)
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

double pa, pb, paa, pab, res;

int K, L;

double dp[128][128][2];
double dp2[128][128][2];
char f[128][128][2];

double calc2(int A, int B, int who)
{
	if (A < 0 || B < 0) return 0.0;
	double &res = dp[A][B][who];
	if (!f[A][B][who])
	{
		f[A][B][who] = 1;
		res = 0;

		if (A)
		{
			if (who)
				res += calc2(A - 1, B, 1) * paa;
			else
				res += calc2(A - 1, B, 1) * pab;
		}
		if (B)
		{
			if (who)
				res += calc2(A, B - 1, 1-who) * (1 - paa);
			else
				res += calc2(A, B - 1, 1-who) * (1 - pab);
		}
//		printf("%d %d %d = %lf\n", A, B, who, res);
	}
	return res;
}

void _calc()
{
	CLA(dp);
	dp[0][0][0] = 1;
	for (int A = 0; A < L; A++)
		for (int B = 0; B <= L; B++)
			for (int who = 0; who < 2; who++)
			{
				dp[A+1][B][0] += dp[A][B][who] * (who ? 1 - pb : pa);
				dp[A][B+1][1] += dp[A][B][who] * (who ? pb : 1 - pa);
			}
	CLA(dp2);
	dp2[0][0][1] = 1;
	for (int A = 0; A < L; A++)
		for (int B = 0; B <= L; B++)
			for (int who = 0; who < 2; who++)
			{
				dp2[A+1][B][0] += dp2[A][B][who] * (who ? 1 - pb : pa);
				dp2[A][B+1][1] += dp2[A][B][who] * (who ? pb : 1 - pa);
			}
}

void _calc2()
{
	CLA(dp); CLA(dp2);
	dp[0][0][0] = 1;
	for (int A = 0; A < K; A++)
		for (int B = 0; B <= K; B++)
			for (int who = 0; who < 2; who++)
			{
				dp[A+1][B][1-who] += dp[A][B][who] * (who ? paa : pab);
				dp[A][B+1][1-who] += dp[A][B][who] * (who ? 1 - paa : 1 - pab);
			}
	dp2[0][0][1] = 1;
	for (int A = 0; A < K; A++)
		for (int B = 0; B <= K; B++)
			for (int who = 0; who < 2; who++)
			{
				dp2[A+1][B][1-who] += dp2[A][B][who] * (who ? paa : pab);
				dp2[A][B+1][1-who] += dp2[A][B][who] * (who ? 1 - paa : 1 - pab);
			}
}


void solve()
{
	_calc();
	paa = 0; pab = 0;
	for (int B = 0; B < L; B++)
		paa += dp[L][B][0] + dp[L][B][1],
		pab += dp2[L][B][0] + dp2[L][B][1];
#ifdef _DEBUG
	printf("    A on A = %lf\n", paa);
	printf("    A on B = %lf\n", pab);
#endif

	_calc2();
	res = 0;
	for (int B = 0; B < K; B++)
		res += dp[K][B][0] + dp[K][B][1],
		res += dp2[K][B][0] + dp2[K][B][1];

}

void result()
{
	printf("%.1lf\n", res * 100.0 / 2);
}

int main()
{
#ifdef _DEBUG
	freopen("1064", "r", stdin);
//	freopen("1064o", "w", stdout);
#endif
	REP(ri())
	{
		pa = ri() / 100.0;
		pb = ri() / 100.0;
		K = ri();
		L = ri();
		solve();
		result();
	}
	return 0;
}

