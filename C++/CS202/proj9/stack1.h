//NAME: Zachary Carlson

//stack stay
class stack{
  public:
  stack(int = 10);
  stack(const stack&);
  ~stack();
  bool push(int);
  int pop();
  bool empty();
  bool full();
  bool clear();
  //overloaded operators
  private:
  int max;
  int actual;
  int top;
  int* data;
};

