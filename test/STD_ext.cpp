#include <STDExtras.hpp>
#include <cstdio>
void unsafe_function(int par)
{
	if (!par)
		throw RUNTIME_EXCEPTION("Error 0")
	else if (par == 5)
		throw RUNTIME_EXCEPTION("Error 5")
}

int main()
{
	int val = 0;
	::std::scanf("%d", &val);

	try {
		unsafe_function(val);
	} DEFAULT_HANDLING

	return 0;
}
