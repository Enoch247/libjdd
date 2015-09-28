#include <sstream>
#include "../StdInt.hpp"

using namespace std;
using namespace jdd;

int main(int argc, char *argv[])
{
    cout << "expect to get:\n"
        << "1 2 3 4 5 6 7 8 9 a b c d e f" << endl;

    stringstream ss;
    ss
        << uint8_be(0x01)
        << uint16_be(0x0203)
        << uint32_be(0x04050607)
        << uint64_be(0x08090a0b0c0d0e0f)
        ;

    string s = ss.str();
    cout << hex;
    for(unsigned int i = 0; i < s.size(); i++)
        cout << (int)s[i] << " ";
    cout << endl;

    return 0;
}

