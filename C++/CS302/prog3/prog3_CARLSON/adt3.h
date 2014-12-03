//Class written by Zachary Carlson
using namespace std;

class stack{
public:
stack(int);
~stack();
int pop();
void push(int);
char name;
int top;
int size;
int* array;
};
