#pragma once

#include <iostream>
#include <string>

class bigint {
public:
	bigint(unsigned int nbr = 0) : _big(nbr == 0 ? "0" : std::to_string(nbr)) {}
	bigint(const bigint &other) : _big(other._big) {}
	bigint &operator=(const bigint &other) {
		if (this != &other)
			_big = other._big;
		return *this;
	}

	std::string getBig() const { return _big; }

	bigint operator+(const bigint &other) const;
	bigint &operator+=(const bigint &other);

	bigint &operator++();
	bigint operator++(int);

	bigint operator<<(unsigned int amount) const;
	bigint &operator<<=(unsigned int amount);
	bigint &operator>>=(const bigint &other);

	bool operator<(const bigint &other) const;
	bool operator>(const bigint &other) const;
	bool operator<=(const bigint &other) const;
	bool operator>=(const bigint &other) const;
	bool operator==(const bigint &other) const;
	bool operator!=(const bigint &other) const;

private:
	std::string _big;
};

std::ostream &operator<<(std::ostream &out, const bigint &other);
