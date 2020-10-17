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
/* (�ǽ� 1-1) �м���� : ���� �Լ����� funcA �Լ��� ȣ���ϸ� funcA���� test ��ü�� ����� funcB �Լ��� ȣ���Ѵ�.
funcB �Լ����� test ��ü�� ����� funcB�� ������ executed �޽����� ȣ���Ѵ�. funcA �Լ����� executed �޽����� ����ϰ�
�����ϸ� �����Լ��� ���ƿ´�. funcB�� ����� �� test b ��ü�� ������� destructor �޽����� ��µǰ� funcA�� ����ɶ����� test a ��ü�� �������. */
/* (�ǽ� 1-2) �м���� : exception�� �߻��ϸ� cout �޽����� ��µ��� �ʰ� test ��ü�� ������鼭 destructor�� ȣ��ȴ�. ������ ���� �Լ����� exception �κ��� ��µȴ�.*/
