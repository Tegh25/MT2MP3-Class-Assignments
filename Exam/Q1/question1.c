#include <assert.h>
#include <math.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

double area(double radius)
{
    return M_PI * radius * radius;
}

// radius of circle r, width of slice
double pieceOfCake(double radius, double width)
{
    double theta = 2 * acos((width / 2) / radius);

    return (theta - sin(theta)) * radius * radius;
}

double pieceOfCakeComplement(double radius, double width)
{
    return area(radius) - pieceOfCake(radius, width);
}

int main () {
	double radius = 42.5;
	double width = 8.2;

	printf("Total Cake = %f\n", area(radius));
	printf("Cake Leftover = %f\n", pieceOfCake(radius, width));
	printf("Cake Obtained = %f\n", pieceOfCakeComplement(radius, width));
}
