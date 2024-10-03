#include <stdio.h>
#include <stdlib.h>
typedef struct {int x; int y; } Point;

Point* create_point(int x, int y) {
    Point* p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

int main(void) {
    Point* origin = create_point(2, 2);
    printf("(%d, %d)", origin->x, origin->y);
    return 0;
}
