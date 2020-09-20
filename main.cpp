
#include <iostream>
#include <stdexcept>

class B {
private:
  std::string msg { "I'm here" };
public:
  B();
  ~B();
  void method(void);
};

B::B() {
  std::cout << "make B" << std::endl;
}
B::~B() {
  std::cout << "unmake B" << std::endl;
}

class A {
private:
  B * b = nullptr;
public:
  A();
  ~A();
  void someMethod(void);
};

A::A() {
  std::cout << "make A" << std::endl;
  b = new B();
};
A::~A() {
  std::cout << "unmake A" << std::endl;
  if (b != nullptr) { delete b; }
};

void A::someMethod(void) {
  std::cout << "b: " << b << std::endl;
  if (b != nullptr) {
    b->method();
  }
  else {
    throw std::runtime_error("B not allocated");
  }
}

void B::method(void) {
  std::cout << msg << std::endl;
}

int main() {
  std::cout << "ShadySingleEmulator" << std::endl;

  A anA;
  std::cout << "a: " << &anA << std::endl; 
  try {
    anA.someMethod();
  }
  catch (std::exception & ex) {
    std::cerr << ex.what() << std::endl;
  }

  return 0;
}
