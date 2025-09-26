#include <iostream>

using namespace std;

enum class Color { RED = 0, BLUE = 1 };

enum class Status : char { ERROR, SUCCESS };

int main() {
    Color c = Color::BLUE;

    cout << (int)c << endl;

    Status status = Status::SUCCESS;

    cout << static_cast<int>(status) << endl;
    return 0;
}