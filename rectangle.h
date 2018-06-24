#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
public:
    // Constructor
    Rectangle(float height, float width);

    // Returns the area of the rectangle
    float get_area();

    // Returns the perimeter of the rectangle
    float get_perimeter();

    // Scale the rectangle by yFactor (changes height) or xFactor (changes width)
    void scale_rectangle(float yFactor, float xFactor);

    // Move the rectangle's x,y coordinates to (newX, newY)
    void move_rectangle(int newX, int newY);

private:
    float height, width;
    float area;
    float perimeter;
    /* The x and y coordinates of the top left corner of the rectangle. (0,0) is the top left corner of the area
    in which the rectangle is located, (5, 3) would be 5 spots over to the right and 3 spots down from the top
    left corner. */
    int x, y;


}




#endif // RECTANGLE_H
