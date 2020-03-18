#include <cmath>

enum class PointType
{
  cartesian,
  polar
};

class Point
{
  /*Point(float a, float b, PointType type = PointType::cartesian)
  {
    if (type == PointType::cartesian)
    {
      x = a; b = y;
    } 
    else
    {
      x = a*cos(b);
      y = a*sin(b);
    }
  }*/

  // use a factory method
  Point(float x, float y) : x(x), y(y){}

    class PointFactory
    {
    PointFactory(){}
    // public이라고 명시해야 한다. Default는 private
    public:
    static Point NewCartesian(float x, float y)
        {
            return Point{ x,y };
        }

    static Point NewPolar(float r, float theta)
        {
            return Point{ r*cos(theta), r*sin(theta) };
        }
        
    };
public:
    float x, y;
    static PointFactory Factory;
};



int main()
{
    // 클래스 내에 존재하는 자식 클래스를 선언함으로써 부모 클래스의 멤버에 접근할 수 있다.
    // Inner Factory라고도 한다.
    auto p = Point::PointFactory::NewCartesian(3,5);
    auto q = Point::PointFactory::NewPolar(5, 43);
    auto r = Point::PointFactory::NewCartesian(3,6);
    auto s = Point::Factory.NewCartesian()


}