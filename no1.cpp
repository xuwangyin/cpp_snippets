class Base {
public:
  Base() { }
  virtual ~Base() { } // virtual destructor
private:
  int b;
  Base(const Base& ); // private make noncopyable
  Base& operator=(const Base&); // private make nonassignable
};


class Derived : public Base {
private:
  int d;
};


int main() {
  Base* b = new Derived;
  // Base b2 = *b; this won't compile, beacause the Base class is
  // noncopyable, which can prevent the Derived object being sliced down

  Derived* d = new Derived;
  // Base b3 = *b; this won't compile, beacause the Base class is
  // noncopyable, which can prevent the Derived object being sliced down

  // virtual destrucotr so that the correct destrucotr get invoked
  delete b;
  delete d;
}
