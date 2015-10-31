#include <iostream>
#include <cmath>

using namespace std;

float rTan(float);

float h(float);
float g(float);


int main() {
    
    cout << "Enter an angle: ";
    float angle;
    cin >> angle;
    cout << "angle is: " << angle << endl;
    
    cout << h(angle) << endl;
    cout << g(angle) << endl;
    cout << rTan(angle) << endl;
    cout << tan(angle) << endl;
    return 0;
}

float rTan(float angle) {
    float tol = 1e-2;
    if (angle>-tol && angle<tol)
        return angle + angle*angle*angle/3;
    return (2*rTan(angle/2))/(1-(rTan(angle/2)*rTan(angle/2)));
}


float h(float x) {
    float tol = 1e-2;
    if (x>-tol && x<tol)
        return x+x*x*x/6;
    return 2*h(x/2)*g(x/2);
}

float g(float x) {
    float tol = 1e-6;
    if (x>-tol && x<tol) {
        return 1 + x*x/2;
    }
    return 1+2*h(x/2)*h(x/2);
}