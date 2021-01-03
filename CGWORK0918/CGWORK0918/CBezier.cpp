#include "pch.h"
#include "CBezier.h"
void CBezier::Bezier(CDC* pdc, CPoint  bezier[4]) {
	//CClientDC dc();
	//DrawpointRectangle_5(&dc, point, 0, 0, 0, 5);
	////四点连线 绘制控制多边形
	//DrawBezRectangle(&dc, bezier);
	////绘制曲线
	////dc.PolyBezier(bezier, 4);
	//double x = 0, bx, by;
	//CPoint mypoint;
	//mypoint = bezier[0];
	//for (double i = 0; i <= 1; i += 0.001)
	//{
	//	x = i;
	//	double parameters[4] = { (1 - x) * (1 - x) * (1 - x), 3 * x * (1 - x) * (1 - x), 3 * x * x * (1 - x), x * x * x };
	//	bx = parameters[0] * bezier[0].x + parameters[1] * bezier[1].x + parameters[2] * bezier[2].x + parameters[3] * bezier[3].x;
	//	by = parameters[0] * bezier[0].y + parameters[1] * bezier[1].y + parameters[2] * bezier[2].y + parameters[3] * bezier[3].y;
	//	//dc.LineTo(bx, by);
	//	DDALine(&dc, mypoint.x, mypoint.y, bx, by);
	//	mypoint.x = bx;
	//	mypoint.y = by;
	//}
}

void CBezier::draw(CDC* pDC) {

}

int CBezier::GetType() {
	return 5;
}