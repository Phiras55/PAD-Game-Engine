#pragma once
#include <array>
#include <varargs.h>
#include <ostream>
#include <tuple>

class Serializer;

#pragma region ARG_COUNT

#define ARG_COUNT(...) ARG_COUNT_IMPL(__VA_ARGS__, MASK)
#define MASK 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
#define OFFSET(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, N, ...) N
#define ARG_COUNT_IMPL(...) MACRO_EXPAND(OFFSET(__VA_ARGS__))

#pragma endregion

#pragma region ARG_LIST_N

 #define ARG_LIST_1(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER
 #define ARG_LIST_2(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_1(STRUCT, __VA_ARGS__))
 #define ARG_LIST_3(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_2(STRUCT, __VA_ARGS__))
 #define ARG_LIST_4(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_3(STRUCT, __VA_ARGS__))
 #define ARG_LIST_5(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_4(STRUCT, __VA_ARGS__))
 #define ARG_LIST_6(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_5(STRUCT, __VA_ARGS__))
 #define ARG_LIST_7(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_6(STRUCT, __VA_ARGS__))
 #define ARG_LIST_8(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_7(STRUCT, __VA_ARGS__))
 #define ARG_LIST_9(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_8(STRUCT, __VA_ARGS__))
#define ARG_LIST_10(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_9(STRUCT, __VA_ARGS__))
#define ARG_LIST_11(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_10(STRUCT, __VA_ARGS__))
#define ARG_LIST_12(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_11(STRUCT, __VA_ARGS__))
#define ARG_LIST_13(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_12(STRUCT, __VA_ARGS__))
#define ARG_LIST_14(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_13(STRUCT, __VA_ARGS__))
#define ARG_LIST_15(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_14(STRUCT, __VA_ARGS__))
#define ARG_LIST_16(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_15(STRUCT, __VA_ARGS__))
#define ARG_LIST_17(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_16(STRUCT, __VA_ARGS__))
#define ARG_LIST_18(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_17(STRUCT, __VA_ARGS__))
#define ARG_LIST_19(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_18(STRUCT, __VA_ARGS__))
#define ARG_LIST_20(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_19(STRUCT, __VA_ARGS__))
#define ARG_LIST_21(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_20(STRUCT, __VA_ARGS__))
#define ARG_LIST_22(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_21(STRUCT, __VA_ARGS__))
#define ARG_LIST_23(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_22(STRUCT, __VA_ARGS__))
#define ARG_LIST_24(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_23(STRUCT, __VA_ARGS__))
#define ARG_LIST_25(STRUCT, MEMBER, ...) &##STRUCT##::##MEMBER , MACRO_EXPAND(ARG_LIST_24(STRUCT, __VA_ARGS__))

#pragma endregion

#pragma region MACRO_EXPAND/CONCAT

#define MACRO_EXPAND(...) __VA_ARGS__
#define MACRO_CONCAT(A, B) A##_##B

#pragma endregion

#pragma region MAKE_META_DATA

#define MAKE_META_DATA(N, ...) public: static constexpr auto META_DATA = std::make_tuple( MACRO_EXPAND(MACRO_CONCAT(ARG_LIST, N)(__VA_ARGS__)) );

#pragma endregion

#pragma region SERIALIZE
/*
template<typename T>
void Serialize(T object)
{
	std::ofstream file("Serialization.txt");
	if (file.isOpen())
	{
		file << "Name:" << decltype(object).name();

	}
	for (int i = 1; i < std::get<0>(object.META_DATA); ++i)
	{
		if (file.is_open())
		{
			auto val = std::get<i>(object.METADATA);
			file << "\t" << decltype(val).name() << ":" << val << "\n";
		}
		file.close();
	}
}
*/
#pragma endregion