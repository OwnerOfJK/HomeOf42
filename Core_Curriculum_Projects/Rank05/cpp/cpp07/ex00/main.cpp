#include "include/Functions.hpp"

// class Point {
//     private:
//         int x, y;
    
//     public:
//         Point(int x, int y) : x(x), y(y) {}
    
//         int getX() const { return x; }
//         int getY() const { return y; }
    
//         bool operator<=(const Point& other) const {
//             return (x <= other.x) && (y <= other.y);
//         }
    
//         void display() const {
//             std::cout << "(" << x << ", " << y << ")" << std::endl;
//         }
//     };

//     std::ostream& operator<<(std::ostream& os, const Point& p) {
//         os << "(" << p.getX() << ", " << p.getY() << ")";
//         return os;
//     }

int main( void ) {
    int a = 2;
    int b = 3;
    swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    int z = 4;
    int y = 4;
    std::cout << "z address: " << &z << std::endl;
    std::cout << "y address: " << &y << std::endl;
    std::cout << "x address: " << &min( z, y ) << std::endl;

    // Point aComplex(3.0, 4.0);
    // Point bComplex(5.0, 12.0);

    // std::cout << "Min: " << min(aComplex, bComplex) << std::endl;
    // std::cout << "Max: " << max(aComplex, bComplex) << std::endl;
    return 0;
}