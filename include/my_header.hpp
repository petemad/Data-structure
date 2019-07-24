
#include <cmath>
double square ( double a )
{
    return a*a;
}
double pythagorean (double x1 , double x2 ,double y1 , double y2  )
{
    return std::sqrt((square (x1-x2)+square(y1-y2)));
} 