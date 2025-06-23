// Дадени са структура Point, описваща точка в декартова координатна система с координати x и y от тип float, и структура Circle,
// описваща окръжност с център center от тип Point и радиус r от тип float.
// Да се дефинира функция findRelativePosition, която определя относителната позиция на две дадени окръжности една спрямо друга.
// Резултатът от изпълнението на функцията е стойност от изброения тип :
//      RelativePosition{ NO_COMMON_POINTS, TOUCHING, INTERSECTING, SAME }.
//  със следния смисъл :
//      NO_COMMON_POINTS : без общи точки
//      TOUCHING : допиращи се
//      INTERSECTING : пресичащи се
//      SAME : съвпада

#include <iostream>
#include <cmath>
#include <iomanip>

struct Point {
	float x, y;
};

struct Circle {
	Point center;
	float radius;
};

enum RelativePosition {
	NO_COMMON_POINTS,
	TOUCHING,
	INTERSECTING,
	SAME
};

RelativePosition findRelativePosition(const Circle& c1, const Circle& c2) {
	double distance = std::sqrt(pow(c1.center.x - c2.center.x, 2) + pow(c1.center.y - c2.center.y, 2));
	const double epsilon = 1e-7;
	if (distance == 0 && c1.radius == c2.radius) {
		return SAME;
	}
	else if (distance > (c1.radius + c2.radius) || distance < std::abs(c1.radius - c2.radius)) {
		return NO_COMMON_POINTS;
	}
	if (std::abs(distance - (c1.radius + c2.radius)) < epsilon ||
		std::abs(distance - std::abs(c1.radius - c2.radius)) < epsilon) {
		return TOUCHING;
	}
	else {
		return INTERSECTING;
	}
}