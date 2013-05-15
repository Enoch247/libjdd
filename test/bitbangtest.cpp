#include <vector>
#include "../bitbang.h"

using namespace std;
using namespace jdd;

int main(int argc, char *argv[])
{
    vector<uint8_t> buffer;
    buffer << uint8_nt(1) << uint16_nt(2) << uint32_nt(3);
    
    for(unsigned int i = 0; i < buffer.size(); i++)
        cout << (int)buffer[i] << " ";
    cout << endl;

    return 0;
}

