#include <iostream>
using namespace std;

template <class T>
class SmartPtr{
private:
	T *obj;
public:
	SmartPtr():obj(new T){};
	SmartPtr(T *arg):obj(arg){};
	SmartPtr(const SmartPtr<T> &arg){
		obj(new T(*arg));
	}
	~SmartPtr(){delete obj;};
	T* operator->()const{return obj;};
	T& operator*()const{return *obj;};
	SmartPtr<T>& operator=(const SmartPtr<T> &arg){
		delete obj;
		obj=new T(*(arg.obj));
		return *this;
	}
};

struct A{
	A(int a_,int b_):a(a_),b(b_){};
	int a,b;
	void display(){cout << a << " " << b << endl;};
};

int main(){
	SmartPtr<A> temp(new A(3,5));
	temp->display();
	SmartPtr<A> temp2(new A(5,3));
	temp=temp2;
	temp->display();
	return 0;
}