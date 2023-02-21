#include <iostream>
#include <cstdint>

#include <int128.hpp>

int* specialPtr()
{
    std::unique_ptr<int> ptr(new int(5));
    printf("ptr is %p\n", ptr.get());
    printf("*ptr = %d\n", *ptr);
    return ptr.get();
}

int main(int argc, char** argv)
{
    uint128_t num;
    num = 5;

    std::pair<uint64_t, bool> addData = uint128_t::addLittleEndian(0x1111111111111111, 0x1);
    printf("val: %d\noverflow: %d\n", addData.first, addData.second);
    addData = uint128_t::addLittleEndian(0xFFFFFFFFFFFFFFFF, 0x1);
    printf("val: %d\noverflow: %d\n", addData.first, addData.second);
    std::cout << &addData.first << std::endl;

    return 0;
}
