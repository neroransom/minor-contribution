#ifndef SEQSTACK_H
#define SEQSTACK_H

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

const int defaultSize = 100;

#pragma region class
template<class T>
class SeqStack
{
public:
    SeqStack(int sz = defaultSize);
    ~SeqStack() { delete[] elements; }
    void Push(const T &x); //isFull栈溢出判断
    bool Pop(T &x);        //isEmpty判断
    bool getTop(T& x);
	bool isEmpty() const { return (top == -1) ? true : false; }
	bool isFull() const { return (top == maxSize - 1) ? true : false; }
    int getSize() const { return top + 1; }
    void MakeEmpty() { top = -1; }
    friend ostream& operator<<(ostream& os, SeqStack<T>& s);      //TODO 
	friend ostream& operator>>(ostream& os, SeqStack<T>& s);      //TODO 
	friend class Calculate;                                  //TODO private problem
	void print();
    T *elements;
    int top;
    int maxSize;                           //TODO private problem
private:
};
#pragma endregion

#pragma region function

template <class T>
SeqStack<T>::SeqStack(int sz) : top(-1),maxSize(sz)
{
    elements = new T[maxSize];
    assert(elements != NULL);
}

template <class T>
void SeqStack<T>::Push(const T& x) 
{
	//公共函数:若栈不满，则将元素x插人到该栈的栈顶，否则溢出处理。
	if (isFull() == true)
	{
		cout << "stack_overflow";  //栈满则报错
		return;
	}
	elements[++top] = x;
}

template <class T>
bool SeqStack<T> ::Pop(T& x) 
{
    if (isEmpty() == true)
    {
        return false; //若栈空则函数返回
    }
    x = elements[top--];
    return true; //退栈成功
}

template < class T>
bool SeqStack<T> ::getTop(T& x) 
{
    //若栈不空则函数返回该栈栈顶元素的地址。
	if (isEmpty() == true)
	{
		return false;     //若栈空则函数返回
	}
	x = elements[top];
    return true; //返回栈顶元素的值
}

template<class T>
inline void SeqStack<T>::print()
{
	 cout << "top=" << top << endl;
	for (int i = 0; i <= top; i++) //逐个输出栈中元素的值
	{
	cout<< i << ":" << elements[i] << endl;
	}
}

#pragma region TO BE SOLVE
template < class T>
ostream& operator << (ostream& os, SeqStack<T>& s) //输出栈中元素的重载操作<<
{
  //  os << "top=" << s.top << endl;
//	for (int i = 0; i <= s.top; i++) //逐个输出栈中元素的值
//	{
//		os << i << ":" << s.elements[i] << endl;
		os << s.elements[0] << endl;
//	}
    return os;
};
#pragma endregion

template < class T>
ostream& operator >> (ostream& os, SeqStack<T>& s) //输出栈中元素的重载操作<<
{
	os >> s.elements[s.top] ;
	return os;
};

#pragma endregion

#endif
