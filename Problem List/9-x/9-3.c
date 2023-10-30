#include <stdio.h>

struct Taget
{
    float x1;
    float x2;
    float y1;
    float y2;
};

void TagetLocate(struct Taget *taget,float *x3,float *y3) 
{
    *x3 = taget->x1 + taget->x2;
    *y3 = taget->y1 + taget->y2;
}

int main()
{
    float x3,y3;
    struct Taget taget;
    scanf("%f%f%f%f", &taget.x1, &taget.y1, &taget.x2, &taget.y2);
    TagetLocate(&taget, &x3, &y3);
    printf("(%.1f, %.1f)",x3,y3);
}