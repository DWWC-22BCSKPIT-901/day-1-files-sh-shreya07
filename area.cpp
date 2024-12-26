#include <iostream> 
 
int area(int l, int b) { return l * b; } 
 
float area(int r) { return 3.14 * r * r; } 
 
float area(float h, float b) { return 0.5 * b * h; } 
 
int main() { 
    int r_l, r_b, c_r = 0;     float t_b, t_h = 0; 
     
    std::cout << "Rectangle  : \n";     std::cin >> r_l;     std::cin >> r_b; 
    std::cout << "Area : " << area(r_l, r_b) << "\n";     std::cout << "\nCircle  : \n";     std::cin >> c_r; 
    std::cout << "Area : " << area(c_r) << "\n";     std::cout << "\nTriangle  : \n";     std::cin >> t_b;     std::cin >> t_h; 
    std::cout << "Area : " << area(t_b, t_h) << "\n"; } 
