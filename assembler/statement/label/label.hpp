#ifndef LLCCEP_ASM_STATEMENT_LABEL_HPP
#define LLCCEP_ASM_STATEMENT_LABEL_HPP

#include <string>

namespace LLCCEP_ASM {
	class label {
		::std::string name;
		size_t pos;

	public:
		label();
		~label();

		void setName(::std::string newName);
		void setPos(size_t newPos);

		::std::string getName() const;
		size_t getPos() const;
	};
}

#endif /* LLCCEP_ASM_STATEMENT_LABEL_HPP */
