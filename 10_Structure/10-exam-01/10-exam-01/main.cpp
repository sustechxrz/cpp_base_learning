/*
HDOJ 2056 Rectangles
https://acm.hdu.edu.cn/showproblem.php?pid=2056
*/


#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point {
	double x;
	double y;
};

struct Rect {
	Point a;
	Point b;
};
Rect R1, R2;
Rect tmp1, tmp2;
int main() {
	while (cin >> tmp1.a.x >> tmp1.a.y >> tmp1.b.x >> tmp1.b.y >> tmp2.a.x >> tmp2.a.y >> tmp2.b.x >> tmp2.b.y) {
		R1.a.x = min(tmp1.a.x, tmp1.b.x);
		R1.a.y = min(tmp1.a.y, tmp1.b.y);
		R1.b.x = max(tmp1.a.x, tmp1.b.x);
		R1.b.y = max(tmp1.a.y, tmp1.b.y);

		R2.a.x = min(tmp2.a.x, tmp2.b.x);
		R2.a.y = min(tmp2.a.y, tmp2.b.y);
		R2.b.x = max(tmp2.a.x, tmp2.b.x);
		R2.b.y = max(tmp2.a.y, tmp2.b.y);

		double maxx = max(R1.a.x, R2.a.x);
		double minx = min(R1.b.x, R2.b.x);
		double maxy = max(R1.a.y, R2.a.y);
		double miny = min(R1.b.y, R2.b.y);
		double ans = (minx - maxx) * (miny - maxy);
		if ((minx < maxx) || (miny < maxy)) {
			ans = 0;
		}
		cout << fixed << setprecision(2) << ans << endl;
		//printf("%.2lf\n", ans);
	}
	
	


}