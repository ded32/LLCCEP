#ifndef LLCCEP_COMPILERCORE_COREINTERFACE_HPP
#define LLCCEP_COMPILERCORE_COREINTERFACE_HPP

#define REQUIRE(expr) \
if (!expr) { \
	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
		"%s is invalid, how expected!", \
		#expr)); \
}

#define MARK(flags, markedFlags) \
flags |= markedFlags;

#define UNMARK(flags, unmarkedFlags) \
flags &= ~unmarkedFlags;

#endif /* LLCCEP_COMPILERCORE_COREINTERFACE_HPP */
