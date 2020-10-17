#include <iostream>
#include <stdexcept>

class Test {
public:
	Test(char id) : id_(id) {}
	~Test() { std::cout << "Destructor execution: " << id_ << std::endl; }
private:
	char id_;
};

int funcB() {
	Test r('B');
	//throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}

int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}

int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* (실습 1-1) 분석결과 : 메인 함수에서 funcA 함수를 호출하면 funcA에서 test 객체를 만들고 funcB 함수를 호출한다.
funcB 함수에서 test 객체를 만들어 funcB가 끝나면 executed 메시지를 호출한다. funcA 함수에서 executed 메시지를 출력하고
리턴하면 메인함수로 돌아온다. funcB가 종료될 때 test b 객체가 사라지고 destructor 메시지가 출력되고 funcA가 종료될때에는 test a 객체가 사라진다. */
/* (실습 1-2) 분석결과 : exception이 발생하면 cout 메시지가 출력되지 않고 test 객체가 사라지면서 destructor만 호출된다. 마지막 메인 함수에서 exception 부분이 출력된다.*/
