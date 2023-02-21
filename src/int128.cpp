#include <iostream>
#include <int128.hpp>

#include <memory>
#include <utility>
#include <vector>

#include <cstdint>

std::pair<std::byte, bool> uint128_t::increment(std::byte thisByte)
{
	if (static_cast<int>(thisByte) == 0xFF)
	{
		return std::pair<std::byte, bool>(std::byte{0x0}, true);
	}
	return std::pair<std::byte, bool>(std::byte{static_cast<unsigned char>(thisByte) + 1}, false);
}

std::pair<std::byte, bool> uint128_t::add(std::byte b1, std::byte b2)
{
	std::pair<std::byte, bool> ret(b1, false);
	std::pair<std::byte, bool> incrementData(std::byte{0x0}, false);

	for (uint64_t i = 0; i < static_cast<uint64_t>(b2); i++)
	{
		incrementData = increment(b1);
		if (incrementData.second)
			ret.second = true;
		ret.first = std::byte{static_cast<unsigned int>(ret.first) + 1};
	}
	return ret;
}

std::pair<uint64_t, bool> uint128_t::addLittleEndian(uint64_t x, uint64_t y)
{
	std::vector<std::byte> xBytes, yBytes, resultBytes;
	xBytes = byteVec(x);
	yBytes = byteVec(y);

	std::pair<std::byte, bool> result;

	result = add(xBytes.at(0), yBytes.at(0));
	resultBytes.push_back(result.first);

	for (uint64_t i = 1; i < sizeof(uint64_t) - 1; i++)
	{
		std::cout << "on iteration " << i << std::endl;
		/* 	this adds the i-th byte of x to the i-th byte of y plus the overflow of the previous byte addition operation. */
		result = add(add(xBytes.at(i), yBytes.at(i)).first, std::byte{static_cast<unsigned char>(result.second)});
		resultBytes.push_back(result.first);
		std::cout << "resultBytes size: " << resultBytes.size() << std::endl;
		std::cout << "iteration done" << std::endl;
	}

	result = add(add(xBytes.at(sizeof(int) - 1), yBytes.at(sizeof(int) - 1)).first, std::byte{static_cast<unsigned char>(result.second)});
	resultBytes.push_back(result.first);
	std::pair<uint64_t, bool> ret;
	ret.second = result.second;

	std::unique_ptr<unsigned char[]> retBytes(new unsigned char[sizeof(unsigned char) * sizeof(uint64_t)]);
	/* note: retBytes.get() is the actual pointer */
	for (uint64_t i = 0; i < sizeof(uint64_t); i++)
	{
		retBytes.get()[i] = static_cast<unsigned char>(resultBytes.at(i));
	}
	
	uint64_t* retIntPtr = (uint64_t*)retBytes.get();
	ret.first = *retIntPtr;

	return ret;
}

bool uint128_t::isLittleEndian()
{
	unsigned int x = 1;
	unsigned char* firstByte = (unsigned char*)&x;
	return *firstByte;
	/* this means that if we declare an int 1, the first byte will only be 0x01 if the memory layout is little-endian */
}

std::vector<std::byte> uint128_t::byteVec(uint64_t num)
{
	std::vector<std::byte> ret;
	unsigned char* rawBytes = (unsigned char*)&num;
	for (int i = 0; i < sizeof(num); i++)
		ret.push_back(std::byte{rawBytes[i]});
	return ret;
}

std::vector<std::byte> uint128_t::byteVec()
{
	std::vector<std::byte> ret;
	unsigned char* rawBytes;
	/* take care of first int */
	rawBytes = (unsigned char*)&this->data.first;
	for (uint64_t i = 0; i < 8; i++)
		ret.push_back(std::byte{rawBytes[i]});
	
	rawBytes = (unsigned char*)&data.second;
	for (uint64_t i = 0; i < 8; i++)
		ret.push_back(std::byte{rawBytes[i]});
	
	return ret;
}

uint128_t::uint128_t()
{
	data.first = 0;
	data.second = 0;
}

uint128_t uint128_t::operator=(uint64_t num)
{
	if (isLittleEndian())
	{
		this->data.first = num;
		this->data.second = 0;
		return *this;
	}

	this->data.second = num;
	this->data.first = 0;
	return *this;
}

uint128_t uint128_t::operator+(uint128_t other)
{
	uint128_t ret;
	if (isLittleEndian())
	{
		/* first add this->data.first and other.data.first. result and the resulting overflow goes into a std::pair<std::byte, std::byte> lowerData */

		/* now add */
	}
}