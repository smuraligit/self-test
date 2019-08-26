#include <iostream>
using namespace std;

template <class T>
class Smartptr {
private:
	T  *ptr;
public:
	explicit Smartptr(T *p = NULL) {
		ptr = p;
	}

	~Smartptr() {
		cout<<endl<<"Destructor of smartptr"<<endl;
		delete(ptr);
	}

	T & operator * () {
		return *ptr;
	}

	T * operator -> () {
		return ptr;
	}

	T * operator & () {
		return ptr;
	}
};
