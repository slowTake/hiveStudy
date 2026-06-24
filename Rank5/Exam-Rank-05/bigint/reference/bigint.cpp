#include "bigint.hpp"

namespace {

std::string normalize(std::string s) {
	std::string::size_type i = 0;
	while (i + 1 < s.size() && s[i] == '0')
		++i;
	s = s.substr(i);
	return s.empty() ? "0" : s;
}

unsigned int toUInt(const std::string &s) {
	unsigned int n = 0;
	for (std::string::size_type i = 0; i < s.size(); ++i)
		n = n * 10 + static_cast<unsigned int>(s[i] - '0');
	return n;
}

} // namespace

bigint bigint::operator+(const bigint &other) const {
	const std::string &a = _big;
	const std::string &b = other._big;
	std::string res;
	int carry = 0;
	int i = static_cast<int>(a.size()) - 1;
	int j = static_cast<int>(b.size()) - 1;

	while (i >= 0 || j >= 0 || carry) {
		int da = i >= 0 ? a[i--] - '0' : 0;
		int db = j >= 0 ? b[j--] - '0' : 0;
		int sum = da + db + carry;
		res.insert(res.begin(), static_cast<char>('0' + sum % 10));
		carry = sum / 10;
	}

	bigint out;
	out._big = normalize(res);
	return out;
}

bigint &bigint::operator+=(const bigint &other) {
	*this = *this + other;
	return *this;
}

bigint &bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint tmp(*this);
	++*this;
	return tmp;
}

bigint bigint::operator<<(unsigned int amount) const {
	if (_big == "0")
		return bigint(0);
	bigint res(*this);
	res._big.append(amount, '0');
	return res;
}

bigint &bigint::operator<<=(unsigned int amount) {
	if (_big != "0")
		_big.append(amount, '0');
	return *this;
}

bigint &bigint::operator>>=(const bigint &other) {
	unsigned int n = toUInt(other._big);
	if (n >= _big.size())
		_big = "0";
	else
		_big = normalize(_big.substr(0, _big.size() - n));
	return *this;
}

bool bigint::operator<(const bigint &other) const {
	if (_big.size() != other._big.size())
		return _big.size() < other._big.size();
	return _big < other._big;
}

bool bigint::operator>(const bigint &other) const { return other < *this; }
bool bigint::operator<=(const bigint &other) const { return !(other < *this); }
bool bigint::operator>=(const bigint &other) const { return !(*this < other); }
bool bigint::operator==(const bigint &other) const { return _big == other._big; }
bool bigint::operator!=(const bigint &other) const { return _big != other._big; }

std::ostream &operator<<(std::ostream &out, const bigint &n) {
	out << n.getBig();
	return out;
}
