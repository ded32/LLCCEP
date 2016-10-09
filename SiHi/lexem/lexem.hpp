#ifndef SIHI_LEXEM_TYPE_HPP
#define SIHI_LEXEM_TYPE_HPP

#include <string>
#include <iostream>

namespace LLCCEP_SiHi {
#define createLexem LLCCEP_SiHi::lexem
#define createAst   new LLCCEP_SiHi::ast

#define PRIMARY_EXPRESSION_LEXEM        createLexem{"Primary expression", LLCCEP_SiHi::PRIMARY_EXPRESSION}
#define POSTFIX_EXPRESSION_LEXEM        createLexem{"Postfix expression", LLCCEP_SiHi::POSTFIX_EXPRESSION}
#define POSTFIX_EXPRESSION_ARRAY_INDEX_ACCESS_LEXEM createLexem{"Postfix expression(array index access)", LLCCEP_SiHi::POSTFIX_EXPRESSION_ARRAY_INDEX_ACCESS}
#define POSTFIX_EXPRESSION_FUNCTION_CALL_LEXEM      createLexem{"Postfix expression(function call)", LLCCEP_SiHi::POSTFIX_EXPRESSION_FUNCTION_CALL}
#define POSTFIX_EXPRESSION_MEMBER_ACCESS_LEXEM      createLexem{"Postfix expression(member access)", LLCCEP_SiHi::POSTFIX_EXPRESSION_MEMBER_ACCESS}
#define POSTFIX_EXPRESSION_MEMBER_ACCESS_PTR_LEXEM  createLexem{"Postfix expression(by-pointer member access)", LLCCEP_SiHi::POSTFIX_EXPRESSION_MEMBER_ACCESS_PTR}
#define POSTFIX_EXPRESSION_INCREMENT_LEXEM          createLexem{"Postfix expression(increment)", LLCCEP_SiHi::POSTFIX_EXPRESSION_INCREMENT}
#define POSTFIX_EXPRESSION_DECREMENT_LEXEM          createLexem{"Postfix expression(decrement)", LLCCEP_SiHi::POSTFIX_EXPRESSION_DECREMENT}
#define ARGUMENT_EXPRESSION_LIST_LEXEM  createLexem{"Argument expression list", LLCCEP_SiHi::ARGUMENT_EXPRESSION_LIST}
#define UNARY_EXPRESSION_LEXEM          createLexem{"Unary expression", LLCCEP_SiHi::UNARY_EXPRESSION}
#define UNARY_OPERATOR_LEXEM            createLexem{"Unary operator", LLCCEP_SiHi::UNARY_OPERATOR}
#define CAST_EXPRESSION_LEXEM           createLexem{"Unary expression", LLCCEP_SiHi::UNARY_EXPRESSION}
#define MULTIPLICATIVE_EXPRESSION_LEXEM createLexem{"Multiplicative expression", LLCCEP_SiHi::MULTIPLICATIVE_EXPRESSION}
#define MULTIPLICATIVE_OPERATOR_LEXEM   createLexem{"Multiplicative operator", LLCCEP_SiHi::MULTIPLICATIVE_OPERATOR}
#define ADDITIVE_EXPRESSION_LEXEM       createLexem{"Additive expression", LLCCEP_SiHi::ADDITIVE_EXPRESSION}
#define ADDITIVE_OPERATOR_LEXEM         createLexem{"Additive operator", LLCCEP_SiHi::ADDITIVE_OPERATOR}
#define SHIFT_EXPRESSION_LEXEM          createLexem{"Shift expression",  LLCCEP_SiHi::SHIFT_EXPRESSION}
#define SHIFT_OPERATOR_LEXEM            createLexem{"Shift operator", LLCCEP_SiHi::SHIFT_OPERATOR}
#define RELATIONAL_EXPRESSION_LEXEM     createLexem{"Relational expression", LLCCEP_SiHi::RELATIONAL_EXPRESSION}
#define RELATIONAL_OPERATOR_LEXEM       createLexem{"Relational operator", LLCCEP_SiHi::RELATIONAL_OPERATOR}
#define EQUALITY_EXPRESSION_LEXEM       createLexem{"Equality expression", LLCCEP_SiHi::EQUALITY_EXPRESSION}
#define EQUALITY_OPERATOR_LEXEM         createLexem{"Equality operator",   LLCCEP_SiHi::EQUALITY_OPERATOR}
#define AND_EXPRESSION_LEXEM            createLexem{"And expression", LLCCEP_SiHi::AND_EXPRESSION}
#define EXCLUSIVE_OR_EXPRESSION_LEXEM   createLexem{"Exclusive or expression", LLCCEP_SiHi::EXCLUSIVE_OR_EXPRESSION}
#define INCLUSIVE_OR_EXPRESSION_LEXEM   createLexem{"Inclusive or expression", LLCCEP_SiHi::INCLUSIVE_OR_EXPRESSION}
#define CONDITIONAL_EXPRESSION_LEXEM    createLexem{"Conditional expression", LLCCEP_SiHi::CONDITIONAL_EXPRESSION}
#define ASSIGNMENT_EXPRESSION_LEXEM     createLexem{"Assignment expression", LLCCEP_SiHi::ASSIGNMENT_EXPRESSION}
#define ASSIGNMENT_OPERATOR_LEXEM       createLexem{"Assignment operator", LLCCEP_SiHi::ASSIGNMENT_OPERATOR}
#define EXPRESSION_LEXEM                createLexem{"Expression", LLCCEP_SiHi::EXPRESSION}
#define CONSTANT_EXPRESSION_LEXEM       createLexem{"Constant expression", LLCCEP_SiHi::CONSTANT_EXPRESSION}
#define DECLARATION_LEXEM               createLexem{"Declaration", LLCCEP_SiHi::DECLARATION}
#define DECLARATION_SPECIFIERS_LEXEM    createLexem{"Declaration specifiers", LLCCEP_SiHi::DECLARATION_SPECIFIERS}
#define INIT_DECLARATOR_LIST_LEXEM      createLexem{"Init declarator list", LLCCEP_SiHi::INIT_DECLARATOR_LIST}
#define INIT_DECLARATOR_LEXEM           createLexem{"Init declarator", LLCCEP_SiHi::INIT_DECLARATOR}
#define TYPE_SPECIFIER_LEXEM            createLexem{"Type specifier", LLCCEP_SiHi::TYPE_SPECIFIER}
#define DECLARATOR_LEXEM                createLexem{"Declarator", LLCCEP_SiHi::DECLARATOR}
#define DIRECT_DECLARATOR_LEXEM         createLexem{"Direct declarator", LLCCEP_SiHi::DIRECT_DECLARATOR}
#define DIRECT_DECLARATOR_SCOPED_LEXEM  createLexem{"Direct declarator: scoped lexem", LLCCEP_SiHi::DIRECT_DECLARATOR_SCOPED}
#define DIRECT_DECLARATOR_ARRAYED_LEXEM createLexem{"Direct declarator: arrayed lexem", LLCCEP_SiHi::DIRECT_DECLARATOR_ARRAYED}
#define DIRECT_DECLARATOR_AUTO_ARRAYED_LEXEM createLexem{"Direct declarator: auto-arrayed lexem", LLCCEP_SiHi::DIRECT_DECLARATOR_ARRAYED}
#define DIRECT_DECLARATOR_PARAMETERS_LIST_LEXEM createLexem{"Direct declarator: parameters list", LLCCEP_SiHi::DIRECT_DECLARATOR_PARAMETERS_LIST}
#define DIRECT_DECLARATOR_IDENTIFIERS_LIST_LEXEM createLexem{"Direct declarator: identifiers list", LLCCEP_SiHi::DIRECT_DECLARATOR_IDENTIFIERS_LIST}
#define POINTER_LEXEM                   createLexem{"Pointer", LLCCEP_SiHi::POINTER}
#define PARAMETER_TYPE_LIST_LEXEM       createLexem{"Parameters type list", LLCCEP_SiHi::PARAMETER_TYPE_LIST}
#define PARAMETER_LIST_LEXEM            createLexem{"Parmeter list", LLCCEP_SiHi::PARAMETER_LIST}
#define PARAMETER_DECLARATION_LEXEM     createLexem{"Parameter declaration", LLCCEP_SiHi::PARAMETER_DECLARATION}
#define IDENTIFIER_LIST_LEXEM           createLexem{"Identifier list", LLCCEP_SiHi::IDENTIFIER_LIST}
#define TYPE_NAME_LEXEM                 createLexem{"Type name", LLCCEP_SiHi::TYPE_NAME}
#define ABSTRACT_DECLARATOR_LEXEM       createLexem{"Abstract declarator", LLCCEP_SiHi::ABSTRACT_DECLARATOR}
#define DIRECT_ABSTRACT_DECLARATOR_LEXEM createLexem{"Direct abstract declarator", LLCCEP_SiHi::DIRECT_ABSTRACT_DECLARATOR}
#define INITIALIZER_LEXEM                createLexem{"Initializer", LLCCEP_SiHi::INITIALIZER}
#define INITIALIZER_LIST_LEXEM           createLexem{"Initializer list", LLCCEP_SiHi::INITIALIZER_LIST}
#define STATEMENT_LEXEM                  createLexem{"Statement", LLCCEP_SiHi::STATEMENT}
#define LABELED_STATEMENT_LEXEM          createLexem{"Labeled statement", LLCCEP_SiHi::LABELED_STATEMENT}
#define COMPOUND_STATEMENT_LEXEM         createLexem{"Compound statement", LLCCEP_SiHi::COMPOUND_STATEMENT}
#define DECLARATION_STATEMENT_LEXEM      createLexem{"Declaration statement", LLCCEP_SiHi::DECLARATION_STATEMENT}
#define DECLARATION_STATEMENT_LIST_LEXEM createLexem{"Declaration statement list", LLCCEP_SiHi::DECLARATION_STATEMENT_LIST}
#define EXPRESSION_STATEMENT_LEXEM       createLexem{"Expression statement", LLCCEP_SiHi::EXPRESSION_STATEMENT}
#define BRANCHED_STATEMENT_LEXEM         createLexem{"Branched statement", LLCCEP_SiHi::BRANCHED_STATEMENT}
#define LOOPED_STATEMENT_LEXEM           createLexem{"Looped statement", LLCCEP_SiHi::LOOPED_STATEMENT}
#define JUMP_STATEMENT_LEXEM             createLexem{"\\\"jump\\\" statement"}
#define NEXT_STATEMENT_LEXEM             createLexem{"\\\"next\\\" statement"}
#define STOP_STATEMENT_LEXEM             createLexem{"\\\"stop\\\" statement"}
#define RETURN_STATEMENT_LEXEM           createLexem{"\\\"return\\\" statement"}
#define TRANSLATION_UNIT_LEXEM           createLexem{"Translation unit", LLCCEP_SiHi::TRANSLATION_UNIT}
#define EXTERNAL_DECLARATION_LEXEM       createLexem{"External declaration", LLCCEP_SiHi::EXTERNAL_DECLARATION}
#define FUNCTION_DEFINITION_LEXEM        createLexem{"Function definition", LLCCEP_SiHi::FUNCTION_DEFINITION}
#define FUNCTION_SIGNATURE_LEXEM         createLexem{"Function signature", LLCCEP_SiHi::FUNCTION_SIGNATURE}
#define FUNCTION_NAME_LEXEM              createLexem{"Function name", LLCCEP_SiHi::FUNCTION_NAME}
#define FUNCTION_ARGS_LEXEM              createLexem{"Function arguments", LLCCEP_SiHi::FUNCTION_ARGS}
#define FUNCTION_TYPE_LEXEM              createLexem{"Function type", LLCCEP_SiHi::FUNCTION_TYPE}
#define LABELED_STATEMENT_LIST_LEXEM     createLexem{"Labeled statement list", LLCCEP_SiHi::LABELED_STATEMENT}
#define CLASS_DECLARATION_LEXEM          createLexem{"Class declaration", LLCCEP_SiHi::CLASS_DECLARATION}
#define CLASSNAME_LEXEM                  createLexem{"Class name", LLCCEP_SiHi::CLASSNAME}
#define PREDECESSOR_LEXEM                createLexem{"Predecessor", LLCCEP_SiHi::PREDECESSOR}
#define METHOD_PROPERTY_LEXEM            createLexem{"Method/property", LLCCEP_SiHi::METHOD_PROPERTY}
#define METHOD_PROPERTY_LIST_LEXEM       createLexem{"Method/property list", LLCCEP_SiHi::METHOD_PROPERTY_LIST}
#define ACCESS_RULE_LEXEM                createLexem{"Access rule", LLCCEP_SiHi::ACCESS_RULE}
#define RELEASEMENT_LEXEM                createLexem{"Variables/fields releasement", LLCCEP_SiHi::RELEASEMENT}
#define EXCEPTION_HANDLING_STATEMENT_LEXEM createLexem{"Exception handling statement", LLCCEP_SiHi::EXCEPTION_HANDLING_STATEMENT}
#define EXCEPTION_THROW_STATEMENT_LEXEM  createLexem{"Exception throw statement", LLCCEP_SiHi::EXCEPTION_THROW_STATEMENT}
#define PASS_STATEMENT_LEXEM             createLexem{"Pass statement", LLCCEP_SiHi::PASS_STATEMENT}
#define INIT_LEXEM                       createLexem{"Class constructor", LLCCEP_SiHi::INIT}
#define DEINIT_LEXEM                     createLexem{"Class destructor", LLCCEP_SiHi::DEINIT}
	enum lex_t: int {
		PRIMARY_EXPRESSION                    = 1024,
		POSTFIX_EXPRESSION                    = 1025,
		ARGUMENT_EXPRESSION_LIST              = 1026,
		UNARY_EXPRESSION                      = 1027,
		UNARY_OPERATOR                        = 1028,
		CAST_EXPRESSION                       = 1029,
		MULTIPLICATIVE_EXPRESSION             = 1030,
		MULTIPLICATIVE_OPERATOR               = 1031,
		ADDITIVE_EXPRESSION                   = 1032,
		ADDITIVE_OPERATOR                     = 1033,
		SHIFT_EXPRESSION                      = 1034,
		SHIFT_OPERATOR                        = 1035,
		RELATIONAL_EXPRESSION                 = 1036,
		RELATIONAL_OPERATOR                   = 1037,
		EQUALITY_EXPRESSION                   = 1038,
		EQUALITY_OPERATOR                     = 1039,
		AND_EXPRESSION                        = 1040,
		EXCLUSIVE_OR_EXPRESSION               = 1041,
		INCLUSIVE_OR_EXPRESSION               = 1042,
		CONDITIONAL_EXPRESSION                = 1043,
		ASSIGNMENT_EXPRESSION                 = 1044,
		ASSIGNMENT_OPERATOR                   = 1045,
		EXPRESSION                            = 1046,
		CONSTANT_EXPRESSION                   = 1047,
		DECLARATION                           = 1048,
		DECLARATION_SPECIFIERS                = 1049,
		INIT_DECLARATOR_LIST                  = 1050,
		INIT_DECLARATOR                       = 1051,
		TYPE_SPECIFIER                        = 1052,
		DECLARATOR                            = 1053,
		DIRECT_DECLARATOR                     = 1054,
		POINTER                               = 1055,
		PARAMETER_TYPE_LIST                   = 1056,
		PARAMETER_LIST                        = 1057,
		PARAMETER_DECLARATION                 = 1058,
		IDENTIFIER_LIST                       = 1059,
		TYPE_NAME                             = 1060,
		ABSTRACT_DECLARATOR                   = 1061,
		DIRECT_ABSTRACT_DECLARATOR            = 1062,
		INITIALIZER                           = 1063,
		INITIALIZER_LIST                      = 1064,
		STATEMENT                             = 1065,
		LABELED_STATEMENT                     = 1066,
		COMPOUND_STATEMENT                    = 1067,
		DECLARATION_STATEMENT                 = 1068,
		DECLARATION_STATEMENT_LIST            = 1069,
		EXPRESSION_STATEMENT                  = 1070,
		BRANCHED_STATEMENT                    = 1071,
		LOOPED_STATEMENT                      = 1072,
		JUMP_STATEMENT                        = 1073,
		TRANSLATION_UNIT                      = 1074,
		EXTERNAL_DECLARATION                  = 1075,
		FUNCTION_DEFINITION                   = 1076,
		FUNCTION_SIGNATURE                    = 1077,
		FUNCTION_NAME                         = 1078,
		FUNCTION_ARGS                         = 1079,
		FUNCTION_TYPE                         = 1080,
		LABELED_STATEMENT_LIST                = 1081,
		CLASS_DECLARATION                     = 1082,
		CLASSNAME                             = 1083,
		PREDECESSOR                           = 1084,
		METHOD_PROPERTY                       = 1085,
		METHOD_PROPERTY_LIST                  = 1086,
		ACCESS_RULE                           = 1087,
		POSTFIX_EXPRESSION_ARRAY_INDEX_ACCESS = 1088,
		POSTFIX_EXPRESSION_DECREMENT          = 1089,
		POSTFIX_EXPRESSION_FUNCTION_CALL      = 1090,
		POSTFIX_EXPRESSION_INCREMENT          = 1091,
		POSTFIX_EXPRESSION_MEMBER_ACCESS      = 1092,
		POSTFIX_EXPRESSION_MEMBER_ACCESS_PTR  = 1093,
		DIRECT_DECLARATOR_ARRAYED             = 1094,
		DIRECT_DECLARATOR_IDENTIFIERS_LIST    = 1095,
		DIRECT_DECLARATOR_PARAMETERS_LIST     = 1096,
		DIRECT_DECLARATOR_SCOPED              = 1097,
		RELEASEMENT                           = 1098,
		EXCEPTION_HANDLING_STATEMENT          = 1099,
		EXCEPTION_THROW_STATEMENT             = 1100,
		PASS_STATEMENT                        = 1101,
		INIT                                  = 1102,
		DEINIT                                = 1103
	};

	struct lexem {
		::std::string value;
		int type;

		::std::string toString(bool enforce = true) const;
	};

	template<typename charT, typename traits>
	::std::basic_ostream<charT, traits> &operator<<(::std::basic_ostream<charT, traits> &out, lexem lex)
	{
		out << lex.toString(false);
		return out;
	}
}

#endif // SIHI_LEXEM_HPP
