#include <stdio.h>
#include <math.h>

/*Declaration of the Structure */

typedef struct Point {
    float x;
    float y;
} Point;


/*Print the coordinates */

void print_point(Point pr) {
    printf("(%.2f, %.2f)\n", pr.x, pr.y);
}

/*Distance from origin */

double distance_from_origin(Point p) {
    return sqrt(p.x*p.x + p.y*p.y); 
}


/* Rotate coordinates by an angle */

void rotate_point(Point *p, float angle) {
float x_new, y_new;   
x_new=(p->x)*cos(3.141*angle/180.0)-(p->y)*sin(3.141*angle/180.0);           
y_new=(p->x)*sin(3.141*angle/180.0)+(p->y)*cos(3.141*angle/180.0);          
p->x = x_new;
p->y=y_new;
}

int main(void) {

Point p;
float x, y, angle;
double dist; 
   
printf("Enter X coordinate: \n");
scanf("%f", &x);
printf("Enter Y coordinate: \n");
scanf("%f", &y);

p.x =x;
p.y=y;

printf("Coordinates you entered:");
print_point(p);

dist=distance_from_origin(p);

printf("\n--------------------\n");
printf("The distance of (%f, %f) from origin: %.2f \n", x,y,dist);

printf("\n--------------------\n");
printf("Enter the angle by which you want to move the point\n");
scanf("%f", &angle);

rotate_point(&p, angle);

printf("\n--------------------\n");
printf("New points: \n");
print_point(p);

return 0;
}