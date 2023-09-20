#include<iostream>
#include<cmath>

class Point {
    int x, y;
public:
    // Default constructor
    Point() : x(0), y(0) {}

    // Parameterized constructor
    Point(int x, int y) : x(x), y(y) {}

    // Copy constructor
    Point(const Point &obj) : x(obj.x), y(obj.y) {}

    // Getter methods
    int getX() const { return x; }
    int getY() const { return y; }

    // Setter methods
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // Overload the minus operator
    Point operator(int val) {
        return Point(x - val, y - val);
    }

    friend Point operator-(int val, const Point &obj) {
        return Point(val - obj.x, val - obj.y);
    }

    // Calculate distance function
    void calculateDistance() const {
        std::cout << "Distance: " << std::abs(x - y) << std::endl;
    }
};

int main() {
    // Create obj1 with value x=5, y=15
    Point obj1(5, 15);

    // Create another obj2 and copy obj1 to obj2
    Point obj2 = obj1;

    // Perform: obj2-2
    obj2 = obj2 - 2;

    // Perform: 1000-obj1
    Point obj3 = 1000 - obj1;

    // Display the values of x and y of obj2 and obj3
    std::cout << "For obj2: x=" << obj2.getX() << ", y=" << obj2.getY() << std::endl;
    std::cout << "For obj3: x=" << obj3.getX() << ", y=" << obj3.getY() << std::endl;

    // Calculate the distance for obj2 and obj3
    std::cout << "For obj2: ";
    obj2.calculateDistance();

     std::cout << "For obj3: ";
     obj3.calculateDistance();

     return 0;
}

