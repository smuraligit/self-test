#include <iostream>
using namespace std;

class Mover {
private:
	int fd;
	virtual int readMover() {
		cout<<"Inside base readMover"<<endl;
		return 0;
	}
	virtual int writeMover() {
		cout<<"Inside base writeMover"<<endl;
		return 0;
	}
public:
    Mover() {
        fd = -1;
    }

    virtual int flushMover() {
    	cout<<"Inside base flushMover"<<endl;
    	return 0;
    }

    virtual ~Mover() {
    	cout<<"Inside base mover destructor"<<endl;
    }
    //This will let main() to invoke private virtual functions, otherwise compile error
    friend int main();
};

class AdhdMover: public Mover {
private:
	//Notice overridden virtual function in derived class, possible because of public virtual function in base class
	int flushMover() {
		cout<<"Inside derived flushMover"<<endl;
		return 0;
	}
public:
	AdhdMover() {

	}
	int readMover() {
		cout<<"Inside adhd readMover"<<endl;
		return 0;
	}
	int writeMover() {
		cout<<"Inside adhd writeMover"<<endl;
		return 0;
	}
	~AdhdMover() {
		cout<<"Inside adhd mover destructor"<<endl;
	}
};

int main() {
	Mover *moverObj = NULL;
	AdhdMover adhdMoverObj;
	moverObj = &adhdMoverObj;
	moverObj->readMover();
	moverObj->writeMover();
	AdhdMover adhdMoverObj1;
	//adhdMoverObj1.flushMover();
	Mover *moverObj1 = &adhdMoverObj1;
	moverObj1->flushMover();
	return 0;
}
