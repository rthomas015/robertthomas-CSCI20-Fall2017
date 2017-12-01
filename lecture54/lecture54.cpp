#include <iostream> 
using namespace std;

class Shape { //* the creation of the Shape class
   private:
      float width_; //? does a shape only have width?
   public:
      void setWidth(float width){ width_ = width; }
      float getWidth() { return width_; }
      float area() { return width_;}
};

class Rectangle : public Shape { //*? both important and unclear. It looks like the class definition of Rectangle is refering to the 
                                 //the parent class Shape
   private:
      float height_;
   public:
      void setLength(float height,float width) { height_ = height; setWidth(width); }
      float getHeight() { return height_; }
      float area() { return height_ * getWidth(); } //? is this an implimentation of polymorphism, the function area occurs in parent
                                                    // and child, but does different things
      float perimeter() { return height_*2 + getWidth()*2; }
};

class Circle : public Shape {
    public:
       float area() { return 3.14 * getWidth()*getWidth(); }
       float circumference() { return 2 * 3.14 * getWidth(); }
};

int main()
{
    Shape s;
    Rectangle r;
    Circle c;
    
    s.setWidth(10);
    r.setLength(10, 2);
    c.setWidth(10);
    
    cout<<"Shape area: "<<s.area()<<endl;
    cout<<"Rectangle area: "<<r.area()<<endl;
    cout<<"Circle area: "<<c.area()<<endl;
    
    cout<<"Rectangle perimeter: "<<r.perimeter()<<endl;
    cout<<"Circle circumference: "<<c.circumference()<<endl;
    
}

//Mark with //* 2-4 items that are important
//Mark with //? 2-4 items that are incorrect, unclear or you have questions about.