/*
  code snippet from
  http://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Core-C-/Stephan-T-Lavavej-Core-C-4-of-n
 */


#include <iostream>
#include <memory>

using namespace std;


class Shape {
public:
  Shape() { }
  virtual ~Shape() { }

  void draw(int x, int y) {
    cout << "non-virtual! Shape::draw(" << x << ", " << y << ")" << endl;

    do_draw(x, y);

    cout << "Shape::draw() says bye!"<< endl;
  }

private:
  virtual void do_draw(int x, int y) = 0;
  Shape(const Shape&);
  Shape& operator=(const Shape&);
};


class Polygon : public Shape {
private:
  virtual void do_draw(int x, int y) {
    cout << "Polygon::do_draw(" << x << ", " << y << ")" << endl;
  }
};

int main() {
  shared_ptr<Shape> sp = make_shared<Polygon>();
  sp->draw(17, 29);
}
