#define INCREMENTSIZE 20

class Stack {
  public:
	Stack();
	~Stack();
	void push(int a);
	int pop();
	void clear();

  private:
  	int size;
	int top;
	int* dane;
};
