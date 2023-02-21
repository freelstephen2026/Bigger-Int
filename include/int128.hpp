#ifndef _INT128_HPP
#define _INT128_HPP

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include <cstdint>

struct uint128_t
{
	std::pair<uint64_t, uint64_t> data;

	static std::pair<std::byte, bool> increment(std::byte); /* return value's template means: <returnValue, overflow> */
	static std::pair<std::byte, bool> add(std::byte, std::byte);
	static std::pair<uint64_t, bool> addLittleEndian(uint64_t, uint64_t);
	static bool isLittleEndian(void);
	static std::vector<std::byte> byteVec(uint64_t);
	
	std::vector<std::byte> byteVec(void);

public:
	uint128_t(void);
	uint128_t operator=(uint64_t);
	uint128_t operator+(uint128_t);
};

#endif
