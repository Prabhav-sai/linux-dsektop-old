#include<stdio.h>
typedef struct rectangle {
    float length;
    float breadth;
} rectangle;

float compute_area(rectangle r) {
    return r.length*r.breadth;
}

rectangle* scale(rectangle* r, float s) {
    (*r).length *= s;
    (*r).breadth *= s;
    return r;
}

int main()
{
    rectangle rect = {  .breadth = 1.0, .length = 3.0} /* {3.0, 1.0 }*/; 		
    // rect.length = 3.2;
    // rect.breadth = 1.2;
    printf("Area of the rectangle is %f \n", compute_area(rect));
    rectangle* rp = scale(&rect, 5);
    printf("Area of the rectangle is %f \n", compute_area(*rp));
    printf("Area of the rectangle is %f \n", compute_area(rect));
} 