/*
When is it possible for an expression's static type to differ from its dynamic type?
Give three examples in which the static and dynamic type differ. 
*/

// ex1: plain pointer
class Shape {
    public: 
        virtual ~Shape() = default; 
};
class Circle : public Shape {};
Shape* p = new Circle();   

// ex2: reference
Circle ci;
Shape &r = ci;

// ex3: smart pointer
std::shared_ptr<Shape> s = std::make_shared<Circle>();
