#ifndef EXEC_FP_HPP
#define EXEC_FP_HPP

#include <cfloat>
#include <algorithm>

#define DBL_EQ(a, b) (::std::abs((a) - (b)) <= DBL_EPSILON)
#define DBL_LESS(a, b) (((a) - (b)) < -DBL_EPSILON)
#define DBL_ABOVE(a, b) (((a) - (b)) > DBL_EPSILON)

#define DBL_AE(a, b) (DBL_EQ(a, b) || DBL_ABOVE(a, b))
#define DBL_LE(a, b) (DBL_EQ(a, b) || DBL_LESS(a, b))

#endif // EXEC_FP_HPP
