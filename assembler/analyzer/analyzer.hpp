#ifndef ANALYZER_HPP
#define ANALYZER_HPP

namespace LLCCEP_ASM {
	class analyzer {
	public:
		analyzer();
		~analyzer();

		void analyze(::std::vector<lexem> lex);
	};
}

#endif // ANALYZER_HPP
