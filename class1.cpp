#include <iostream>;

using namespace std;

class SpacePort
{
public:
    // ������� ���������, � ������� size ���� �����.
    // ���� ���������� �� 0 �� size-1.
    // � ������ �������� ��� ���� ��������.
    SpacePort(unsigned int size);

    ~SpacePort();

    // ��������� ������� � ��� � ������� dockNumber.
    // ���� ������ ���� ��� - ������� false (������ �������).
    // ���� ��� ����, �� ����� - ������� false (������ �������).
    // ���� ��� ���� � �������� - ������� true (���������� �������) � ��� ���������� �����.
    bool requestLanding(unsigned int dockNumber);

    // ��������� ���� �� ���� � ������� dockNumber.
    // ���� ������ ���� ��� - ������� false (������ �����).
    // ���� ��� ����, �� ��� ����� - ������� false (������ �����).
    // ���� ��� ���� � � �� ���-�� ����� - ������� true (���������� �����) � ��� ���������� ��������.
    bool requestTakeoff(unsigned int dockNumber);

private:
    unsigned int* docks;
    unsigned int size;
};

SpacePort::SpacePort(unsigned int size){
    this->size = size;
    this->docks = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++)
        this->docks[i] = 0;
}

SpacePort::~SpacePort(){
    delete[] this->docks;
}

bool SpacePort::requestLanding(unsigned int dockNumber){
    if (dockNumber > (this->size - 1))
        return false;
    if (this->docks[dockNumber] == 1)
        return false;
    if (this->docks[dockNumber] == 0){
        this->docks[dockNumber] = 1;
        return true;
    }
    else return false;
}

bool SpacePort::requestTakeoff(unsigned int dockNumber){
    if (dockNumber > (this->size - 1))
        return false;
    if (this->docks[dockNumber] == 0)
        return false;
    if (this->docks[dockNumber] == 1){
        this->docks[dockNumber] = 0;
        return true;
    }
    else return false;
}

 int main(){
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;

    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;
 }



