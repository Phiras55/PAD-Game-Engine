#pragma once
#include <array>
#include <varargs.h>

#pragma region ARG_COUNT

#define ARG_COUNT(...) ARG_COUNT_IMPL(__VA_ARGS__, MASK())
#define MASK() 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
#define OFFSET(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, N, ...) N
#define ARG_COUNT_IMPL(...) MACRO_EXPAND(OFFSET(__VA_ARGS__))

#pragma endregion

#pragma region ARG_LIST_N

#define ARG_LIST_1(val, ...) #val
#define ARG_LIST_2(val, ...) #val , MACRO_EXPAND(ARG_LIST_1(__VA_ARGS__))
#define ARG_LIST_3(val, ...) #val , MACRO_EXPAND(ARG_LIST_2(__VA_ARGS__))
#define ARG_LIST_4(val, ...) #val , MACRO_EXPAND(ARG_LIST_3(__VA_ARGS__))
#define ARG_LIST_5(val, ...) #val , MACRO_EXPAND(ARG_LIST_4(__VA_ARGS__))
#define ARG_LIST_6(val, ...) #val , MACRO_EXPAND(ARG_LIST_5(__VA_ARGS__))
#define ARG_LIST_7(val, ...) #val , MACRO_EXPAND(ARG_LIST_6(__VA_ARGS__))
#define ARG_LIST_8(val, ...) #val , MACRO_EXPAND(ARG_LIST_7(__VA_ARGS__))
#define ARG_LIST_9(val, ...) #val , MACRO_EXPAND(ARG_LIST_8(__VA_ARGS__))
#define ARG_LIST_10(val, ...) #val , MACRO_EXPAND(ARG_LIST_9(__VA_ARGS__))
#define ARG_LIST_11(val, ...) #val , MACRO_EXPAND(ARG_LIST_10(__VA_ARGS__))
#define ARG_LIST_12(val, ...) #val , MACRO_EXPAND(ARG_LIST_11(__VA_ARGS__))
#define ARG_LIST_13(val, ...) #val , MACRO_EXPAND(ARG_LIST_12(__VA_ARGS__))
#define ARG_LIST_14(val, ...) #val , MACRO_EXPAND(ARG_LIST_13(__VA_ARGS__))
#define ARG_LIST_15(val, ...) #val , MACRO_EXPAND(ARG_LIST_14(__VA_ARGS__))
#define ARG_LIST_16(val, ...) #val , MACRO_EXPAND(ARG_LIST_15(__VA_ARGS__))
#define ARG_LIST_17(val, ...) #val , MACRO_EXPAND(ARG_LIST_16(__VA_ARGS__))
#define ARG_LIST_18(val, ...) #val , MACRO_EXPAND(ARG_LIST_17(__VA_ARGS__))
#define ARG_LIST_19(val, ...) #val , MACRO_EXPAND(ARG_LIST_18(__VA_ARGS__))
#define ARG_LIST_20(val, ...) #val , MACRO_EXPAND(ARG_LIST_19(__VA_ARGS__))
#define ARG_LIST_21(val, ...) #val , MACRO_EXPAND(ARG_LIST_20(__VA_ARGS__))
#define ARG_LIST_22(val, ...) #val , MACRO_EXPAND(ARG_LIST_21(__VA_ARGS__))
#define ARG_LIST_23(val, ...) #val , MACRO_EXPAND(ARG_LIST_22(__VA_ARGS__))
#define ARG_LIST_24(val, ...) #val , MACRO_EXPAND(ARG_LIST_23(__VA_ARGS__))
#define ARG_LIST_25(val, ...) #val , MACRO_EXPAND(ARG_LIST_24(__VA_ARGS__))

#pragma endregion

#pragma region MACRO_EXPAND/CONCAT

#define MACRO_EXPAND(...) __VA_ARGS__
#define MACRO_CONCAT(A, B) A##_##B

#pragma endregion

#pragma region MAKE_META_DATA

#define MAKE_META_DATA(NAME, ...) /*friend Serializer;*/MAKE_META_DATA_IMPL(NAME, ARG_COUNT(__VA_ARGS__), __VA_ARGS__)
#define MAKE_META_DATA_IMPL(NAME, N, ...) constexpr std::array<const char*, N> meta_##NAME = { MACRO_EXPAND(MACRO_CONCAT(ARG_LIST, N)(__VA_ARGS__)) };

#pragma endregion