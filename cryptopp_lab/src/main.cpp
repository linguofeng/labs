#include <iostream>
#include <aes.h>

using namespace std;
using namespace CryptoPP;

int main()
{
    cout << "hello crypto++" << endl;
    cout << "Aes block size is " << AES::BLOCKSIZE << endl;
   
    return 0;
}
