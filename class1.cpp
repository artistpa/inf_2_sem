#include <iostream>;

using namespace std;

class SpacePort
{
public:
    // Создать космодром, в котором size штук доков.
    // Доки нумеруются от 0 до size-1.
    // В момент создания все доки свободны.
    SpacePort(unsigned int size);

    ~SpacePort();

    // Запросить посадку в док с номером dockNumber.
    // Если такого дока нет - вернуть false (запрет посадки).
    // Если док есть, но занят - вернуть false (запрет посадки).
    // Если док есть и свободен - вернуть true (разрешение посадки) и док становится занят.
    bool requestLanding(unsigned int dockNumber);

    // Запросить взлёт из дока с номером dockNumber.
    // Если такого дока нет - вернуть false (запрет взлёта).
    // Если док есть, но там пусто - вернуть false (запрет взлёта).
    // Если док есть и в нём кто-то стоит - вернуть true (разрешение взлёта) и док становится свободен.
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



