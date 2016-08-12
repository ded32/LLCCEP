#ifndef OS_SPECIFIC_HPP
#define OS_SPECIFIC_HPP

#ifdef _WIN32
#define int8_t_pf "%I8d"
#define uint8_t_pf "%c"
#define int16_t_pf "%I16d"
#define uint16_t_pf "%I16u"
#define int32_t_pf "%I32d"
#define uint32_t_pf "%I32u"
#define int64_t_pf "%I64d"
#define uint64_t_pf "%I64u"
#define size_t_pf "%Iu"
#else
#define int8_t_pf "%d"
#define uint8_t_pf "%c"
#define int16_t_pf "%d"
#define uint16_t_pf "%u"
#define int32_t_pf "%ld"
#define uint32_t_pf "%lu"
#define int64_t_pf "%lld"
#define uint64_t_pf "%llu"
#define size_t_pf "%zu"
#endif // _WIN32

#endif // OS_SPECIFIC_HPP