class Base {
public:
  Base() { }
  virtual ~Base() { } // virtual destructor
private:
  int b;
  Base(const Base& ); // noncopyable
  Base& operator=(const Base&); // nonassignable
};


class Derived : public Base {
private:
  int d;
};


int main() {
  Base* b = new Derived;
  // Base b2 = *b; this won't compile, beacause the Base class is
  // noncopyable, which can prevent the Derived object being slicing down

  Derived* d = new Derived;
  // Base b3 = *b; this won't compile, beacause the Base class is
  // noncopyable, which can prevent the Derived object being slicing down

  // virtual destrucotr so that the correct destrucotr get invoked
  delete b;
  delete d;
}
