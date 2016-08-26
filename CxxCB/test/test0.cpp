#include <iostream>
#include <regex>
#include <string>

int main()
{
	::std::string in;
	::std::regex integer("(\\+|-)?[0-9]+", ::std::regex_constants::egrep);
	
	while (in != "leave") {
		::std::getline(::std::cin, in);

		if (::std::regex_match(in, integer)) {
			::std::cout << "Integer\n";
		} else {
			::std::cout << "Not integer\n";
		}
	}

	return 0;
}
