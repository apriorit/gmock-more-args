#pragma once
#include <gmock/internal/gmock-port.h>

#ifdef GMOCK_INTERNAL_MOCK_METHODN // Intorduced in gMock 1.11.0

#define MOCK_METHOD11(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 11, __VA_ARGS__)
#define MOCK_METHOD12(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 12, __VA_ARGS__)
#define MOCK_METHOD13(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 13, __VA_ARGS__)
#define MOCK_METHOD14(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 14, __VA_ARGS__)
#define MOCK_METHOD15(m, ...) GMOCK_INTERNAL_MOCK_METHODN(, , m, 15, __VA_ARGS__)

#define MOCK_CONST_METHOD11(m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, , m, 11, __VA_ARGS__)
#define MOCK_CONST_METHOD12(m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, , m, 12, __VA_ARGS__)
#define MOCK_CONST_METHOD13(m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, , m, 13, __VA_ARGS__)
#define MOCK_CONST_METHOD14(m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, , m, 14, __VA_ARGS__)
#define MOCK_CONST_METHOD15(m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, , m, 15, __VA_ARGS__)

#define MOCK_METHOD11_T(m, ...) MOCK_METHOD11(m, __VA_ARGS__)
#define MOCK_METHOD12_T(m, ...) MOCK_METHOD12(m, __VA_ARGS__)
#define MOCK_METHOD13_T(m, ...) MOCK_METHOD13(m, __VA_ARGS__)
#define MOCK_METHOD14_T(m, ...) MOCK_METHOD14(m, __VA_ARGS__)
#define MOCK_METHOD15_T(m, ...) MOCK_METHOD15(m, __VA_ARGS__)

#define MOCK_CONST_METHOD11_T(m, ...) MOCK_CONST_METHOD11(m, __VA_ARGS__)
#define MOCK_CONST_METHOD12_T(m, ...) MOCK_CONST_METHOD12(m, __VA_ARGS__)
#define MOCK_CONST_METHOD13_T(m, ...) MOCK_CONST_METHOD13(m, __VA_ARGS__)
#define MOCK_CONST_METHOD14_T(m, ...) MOCK_CONST_METHOD14(m, __VA_ARGS__)
#define MOCK_CONST_METHOD15_T(m, ...) MOCK_CONST_METHOD15(m, __VA_ARGS__)

#define MOCK_METHOD11_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 11, __VA_ARGS__)
#define MOCK_METHOD12_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 12, __VA_ARGS__)
#define MOCK_METHOD13_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 13, __VA_ARGS__)
#define MOCK_METHOD14_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 14, __VA_ARGS__)
#define MOCK_METHOD15_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(, ct, m, 15, __VA_ARGS__)

#define MOCK_CONST_METHOD11_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 11, __VA_ARGS__)
#define MOCK_CONST_METHOD12_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 12, __VA_ARGS__)
#define MOCK_CONST_METHOD13_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 13, __VA_ARGS__)
#define MOCK_CONST_METHOD14_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 14, __VA_ARGS__)
#define MOCK_CONST_METHOD15_WITH_CALLTYPE(ct, m, ...) GMOCK_INTERNAL_MOCK_METHODN(const, ct, m, 15, __VA_ARGS__)

#define MOCK_METHOD11_T_WITH_CALLTYPE(ct, m, ...) MOCK_METHOD11_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD12_T_WITH_CALLTYPE(ct, m, ...) MOCK_METHOD12_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD13_T_WITH_CALLTYPE(ct, m, ...) MOCK_METHOD13_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD14_T_WITH_CALLTYPE(ct, m, ...) MOCK_METHOD14_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_METHOD15_T_WITH_CALLTYPE(ct, m, ...) MOCK_METHOD15_WITH_CALLTYPE(ct, m, __VA_ARGS__)

#define MOCK_CONST_METHOD11_T_WITH_CALLTYPE(ct, m, ...) MOCK_CONST_METHOD11_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD12_T_WITH_CALLTYPE(ct, m, ...) MOCK_CONST_METHOD12_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD13_T_WITH_CALLTYPE(ct, m, ...) MOCK_CONST_METHOD13_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD14_T_WITH_CALLTYPE(ct, m, ...) MOCK_CONST_METHOD14_WITH_CALLTYPE(ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD15_T_WITH_CALLTYPE(ct, m, ...) MOCK_CONST_METHOD15_WITH_CALLTYPE(ct, m, __VA_ARGS__)

#else

namespace testing
{
    namespace internal 
    {

//
// Definitions for 11 arguments
//
#define GMOCK_METHOD11_(tn, constness, ct, Method, ...) \
  static_assert(11 == \
      ::testing::internal::Function<__VA_ARGS__>::ArgumentCount, \
      "MOCK_METHOD<N> must match argument count.");\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, GMOCK_ARG_(tn, 2, \
          __VA_ARGS__) gmock_a2, GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
          GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, GMOCK_ARG_(tn, 5, \
          __VA_ARGS__) gmock_a5, GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
          GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, GMOCK_ARG_(tn, 8, \
          __VA_ARGS__) gmock_a8, GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
          GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11) constness { \
    GMOCK_MOCKER_(11, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(11, constness, \
        Method).Invoke(::std::forward<GMOCK_ARG_(tn, 1, \
        __VA_ARGS__)>(gmock_a1), \
  ::std::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(gmock_a2), \
  ::std::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(gmock_a3), \
  ::std::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(gmock_a4), \
  ::std::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(gmock_a5), \
  ::std::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(gmock_a6), \
  ::std::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(gmock_a7), \
  ::std::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(gmock_a8), \
  ::std::forward<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(gmock_a9), \
  ::std::forward<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(gmock_a10), \
  ::std::forward<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(gmock_a11)); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10,__VA_ARGS__) gmock_a10,\
                     GMOCK_MATCHER_(tn, 11,__VA_ARGS__) gmock_a11) constness { \
    GMOCK_MOCKER_(11, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(11, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11); \
  } \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method( \
      const ::testing::internal::WithoutMatchers&, \
      constness ::testing::internal::Function<__VA_ARGS__>* ) const { \
        return ::testing::internal::AdjustConstness_##constness(this)-> \
            gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 11, __VA_ARGS__)>()); \
      } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(11, constness, \
      Method)

#define MOCK_METHOD11(m, ...) GMOCK_METHOD11_(, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD11(m, ...) GMOCK_METHOD11_(, const, , m, __VA_ARGS__)
#define MOCK_METHOD11_T(m, ...) GMOCK_METHOD11_(typename, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD11_T(m, ...) \
    GMOCK_METHOD11_(typename, const, , m, __VA_ARGS__)
#define MOCK_METHOD11_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD11_(, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD11_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD11_(, const, ct, m, __VA_ARGS__)
#define MOCK_METHOD11_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD11_(typename, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD11_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD11_(typename, const, ct, m, __VA_ARGS__)

//
// Definitions for 12 arguments
//
#define GMOCK_METHOD12_(tn, constness, ct, Method, ...) \
  static_assert(12 == \
      ::testing::internal::Function<__VA_ARGS__>::ArgumentCount, \
      "MOCK_METHOD<N> must match argument count.");\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, GMOCK_ARG_(tn, 2, \
          __VA_ARGS__) gmock_a2, GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
          GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, GMOCK_ARG_(tn, 5, \
          __VA_ARGS__) gmock_a5, GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
          GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, GMOCK_ARG_(tn, 8, \
          __VA_ARGS__) gmock_a8, GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
          GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
          GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12) constness { \
    GMOCK_MOCKER_(12, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(12, constness, \
        Method).Invoke(::std::forward<GMOCK_ARG_(tn, 1, \
        __VA_ARGS__)>(gmock_a1), \
  ::std::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(gmock_a2), \
  ::std::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(gmock_a3), \
  ::std::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(gmock_a4), \
  ::std::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(gmock_a5), \
  ::std::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(gmock_a6), \
  ::std::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(gmock_a7), \
  ::std::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(gmock_a8), \
  ::std::forward<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(gmock_a9), \
  ::std::forward<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(gmock_a10), \
  ::std::forward<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(gmock_a11), \
  ::std::forward<GMOCK_ARG_(tn, 12, __VA_ARGS__)>(gmock_a12)); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10,__VA_ARGS__) gmock_a10,\
                     GMOCK_MATCHER_(tn, 11,__VA_ARGS__) gmock_a11,\
                     GMOCK_MATCHER_(tn, 12,__VA_ARGS__) gmock_a12) constness { \
    GMOCK_MOCKER_(12, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(12, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12); \
  } \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method( \
      const ::testing::internal::WithoutMatchers&, \
      constness ::testing::internal::Function<__VA_ARGS__>* ) const { \
        return ::testing::internal::AdjustConstness_##constness(this)-> \
            gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 12, __VA_ARGS__)>()); \
      } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(12, constness, \
      Method)

#define MOCK_METHOD12(m, ...) GMOCK_METHOD12_(, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD12(m, ...) GMOCK_METHOD12_(, const, , m, __VA_ARGS__)
#define MOCK_METHOD12_T(m, ...) GMOCK_METHOD12_(typename, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD12_T(m, ...) \
    GMOCK_METHOD12_(typename, const, , m, __VA_ARGS__)
#define MOCK_METHOD12_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD12_(, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD12_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD12_(, const, ct, m, __VA_ARGS__)
#define MOCK_METHOD12_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD12_(typename, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD12_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD12_(typename, const, ct, m, __VA_ARGS__)

//
// Definitions for 13 arguments
//
#define GMOCK_METHOD13_(tn, constness, ct, Method, ...) \
  static_assert(13 == \
      ::testing::internal::Function<__VA_ARGS__>::ArgumentCount, \
      "MOCK_METHOD<N> must match argument count.");\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, GMOCK_ARG_(tn, 2, \
          __VA_ARGS__) gmock_a2, GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
          GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, GMOCK_ARG_(tn, 5, \
          __VA_ARGS__) gmock_a5, GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
          GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, GMOCK_ARG_(tn, 8, \
          __VA_ARGS__) gmock_a8, GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
          GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
          GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13) constness { \
    GMOCK_MOCKER_(13, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(13, constness, \
        Method).Invoke(::std::forward<GMOCK_ARG_(tn, 1, \
        __VA_ARGS__)>(gmock_a1), \
  ::std::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(gmock_a2), \
  ::std::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(gmock_a3), \
  ::std::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(gmock_a4), \
  ::std::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(gmock_a5), \
  ::std::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(gmock_a6), \
  ::std::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(gmock_a7), \
  ::std::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(gmock_a8), \
  ::std::forward<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(gmock_a9), \
  ::std::forward<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(gmock_a10), \
  ::std::forward<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(gmock_a11), \
  ::std::forward<GMOCK_ARG_(tn, 12, __VA_ARGS__)>(gmock_a12), \
  ::std::forward<GMOCK_ARG_(tn, 13, __VA_ARGS__)>(gmock_a13)); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10,__VA_ARGS__) gmock_a10,\
                     GMOCK_MATCHER_(tn, 11,__VA_ARGS__) gmock_a11,\
                     GMOCK_MATCHER_(tn, 12,__VA_ARGS__) gmock_a12,\
                     GMOCK_MATCHER_(tn, 13,__VA_ARGS__) gmock_a13) constness { \
    GMOCK_MOCKER_(13, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(13, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13); \
  } \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method( \
      const ::testing::internal::WithoutMatchers&, \
      constness ::testing::internal::Function<__VA_ARGS__>* ) const { \
        return ::testing::internal::AdjustConstness_##constness(this)-> \
            gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 12, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 13, __VA_ARGS__)>()); \
      } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(13, constness, \
      Method)

#define MOCK_METHOD13(m, ...) GMOCK_METHOD13_(, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD13(m, ...) GMOCK_METHOD13_(, const, , m, __VA_ARGS__)
#define MOCK_METHOD13_T(m, ...) GMOCK_METHOD13_(typename, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD13_T(m, ...) \
    GMOCK_METHOD13_(typename, const, , m, __VA_ARGS__)
#define MOCK_METHOD13_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD13_(, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD13_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD13_(, const, ct, m, __VA_ARGS__)
#define MOCK_METHOD13_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD13_(typename, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD13_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD13_(typename, const, ct, m, __VA_ARGS__)

//
// Definitions for 14 arguments
//
#define GMOCK_METHOD14_(tn, constness, ct, Method, ...) \
  static_assert(14 == \
      ::testing::internal::Function<__VA_ARGS__>::ArgumentCount, \
      "MOCK_METHOD<N> must match argument count.");\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, GMOCK_ARG_(tn, 2, \
          __VA_ARGS__) gmock_a2, GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
          GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, GMOCK_ARG_(tn, 5, \
          __VA_ARGS__) gmock_a5, GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
          GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, GMOCK_ARG_(tn, 8, \
          __VA_ARGS__) gmock_a8, GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
          GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
          GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
          GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14) constness { \
    GMOCK_MOCKER_(14, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(14, constness, \
        Method).Invoke(::std::forward<GMOCK_ARG_(tn, 1, \
        __VA_ARGS__)>(gmock_a1), \
  ::std::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(gmock_a2), \
  ::std::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(gmock_a3), \
  ::std::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(gmock_a4), \
  ::std::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(gmock_a5), \
  ::std::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(gmock_a6), \
  ::std::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(gmock_a7), \
  ::std::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(gmock_a8), \
  ::std::forward<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(gmock_a9), \
  ::std::forward<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(gmock_a10), \
  ::std::forward<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(gmock_a11), \
  ::std::forward<GMOCK_ARG_(tn, 12, __VA_ARGS__)>(gmock_a12), \
  ::std::forward<GMOCK_ARG_(tn, 13, __VA_ARGS__)>(gmock_a13), \
  ::std::forward<GMOCK_ARG_(tn, 14, __VA_ARGS__)>(gmock_a14)); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10,__VA_ARGS__) gmock_a10,\
                     GMOCK_MATCHER_(tn, 11,__VA_ARGS__) gmock_a11,\
                     GMOCK_MATCHER_(tn, 12,__VA_ARGS__) gmock_a12,\
                     GMOCK_MATCHER_(tn, 13,__VA_ARGS__) gmock_a13,\
                     GMOCK_MATCHER_(tn, 14,__VA_ARGS__) gmock_a14) constness { \
    GMOCK_MOCKER_(14, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(14, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14); \
  } \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method( \
      const ::testing::internal::WithoutMatchers&, \
      constness ::testing::internal::Function<__VA_ARGS__>* ) const { \
        return ::testing::internal::AdjustConstness_##constness(this)-> \
            gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 12, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 13, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 14, __VA_ARGS__)>()); \
      } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(14, constness, \
      Method)

#define MOCK_METHOD14(m, ...) GMOCK_METHOD14_(, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD14(m, ...) GMOCK_METHOD14_(, const, , m, __VA_ARGS__)
#define MOCK_METHOD14_T(m, ...) GMOCK_METHOD14_(typename, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD14_T(m, ...) \
    GMOCK_METHOD14_(typename, const, , m, __VA_ARGS__)
#define MOCK_METHOD14_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD14_(, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD14_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD14_(, const, ct, m, __VA_ARGS__)
#define MOCK_METHOD14_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD14_(typename, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD14_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD14_(typename, const, ct, m, __VA_ARGS__)

//
// Definitions for 15 arguments
//
#define GMOCK_METHOD15_(tn, constness, ct, Method, ...) \
  static_assert(15 == \
      ::testing::internal::Function<__VA_ARGS__>::ArgumentCount, \
      "MOCK_METHOD<N> must match argument count.");\
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, GMOCK_ARG_(tn, 2, \
          __VA_ARGS__) gmock_a2, GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
          GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, GMOCK_ARG_(tn, 5, \
          __VA_ARGS__) gmock_a5, GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
          GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, GMOCK_ARG_(tn, 8, \
          __VA_ARGS__) gmock_a8, GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
          GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10, GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
          GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
          GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14, GMOCK_ARG_(tn, 15, __VA_ARGS__) gmock_a15) constness { \
    GMOCK_MOCKER_(15, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(15, constness, \
        Method).Invoke(::std::forward<GMOCK_ARG_(tn, 1, \
        __VA_ARGS__)>(gmock_a1), \
  ::std::forward<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(gmock_a2), \
  ::std::forward<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(gmock_a3), \
  ::std::forward<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(gmock_a4), \
  ::std::forward<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(gmock_a5), \
  ::std::forward<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(gmock_a6), \
  ::std::forward<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(gmock_a7), \
  ::std::forward<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(gmock_a8), \
  ::std::forward<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(gmock_a9), \
  ::std::forward<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(gmock_a10), \
  ::std::forward<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(gmock_a11), \
  ::std::forward<GMOCK_ARG_(tn, 12, __VA_ARGS__)>(gmock_a12), \
  ::std::forward<GMOCK_ARG_(tn, 13, __VA_ARGS__)>(gmock_a13), \
  ::std::forward<GMOCK_ARG_(tn, 14, __VA_ARGS__)>(gmock_a14), \
  ::std::forward<GMOCK_ARG_(tn, 15, __VA_ARGS__)>(gmock_a15)); \
  } \
  ::testing::MockSpec<__VA_ARGS__> \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10,__VA_ARGS__) gmock_a10,\
                     GMOCK_MATCHER_(tn, 11,__VA_ARGS__) gmock_a11,\
                     GMOCK_MATCHER_(tn, 12,__VA_ARGS__) gmock_a12,\
                     GMOCK_MATCHER_(tn, 13,__VA_ARGS__) gmock_a13,\
                     GMOCK_MATCHER_(tn, 14,__VA_ARGS__) gmock_a14,\
                     GMOCK_MATCHER_(tn, 15,__VA_ARGS__) gmock_a15) constness { \
    GMOCK_MOCKER_(15, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(15, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14, gmock_a15); \
  } \
  ::testing::MockSpec<__VA_ARGS__> gmock_##Method( \
      const ::testing::internal::WithoutMatchers&, \
      constness ::testing::internal::Function<__VA_ARGS__>* ) const { \
        return ::testing::internal::AdjustConstness_##constness(this)-> \
            gmock_##Method(::testing::A<GMOCK_ARG_(tn, 1, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 2, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 3, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 4, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 5, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 6, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 7, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 8, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 9, __VA_ARGS__)>(), \
                     ::testing::A<GMOCK_ARG_(tn, 10, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 11, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 12, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 13, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 14, __VA_ARGS__)>(),\
                     ::testing::A<GMOCK_ARG_(tn, 15, __VA_ARGS__)>()); \
      } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(15, constness, \
      Method)

#define MOCK_METHOD15(m, ...) GMOCK_METHOD15_(, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD15(m, ...) GMOCK_METHOD15_(, const, , m, __VA_ARGS__)
#define MOCK_METHOD15_T(m, ...) GMOCK_METHOD15_(typename, , , m, __VA_ARGS__)
#define MOCK_CONST_METHOD15_T(m, ...) \
    GMOCK_METHOD15_(typename, const, , m, __VA_ARGS__)
#define MOCK_METHOD15_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD15_(, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD15_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD15_(, const, ct, m, __VA_ARGS__)
#define MOCK_METHOD15_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD15_(typename, , ct, m, __VA_ARGS__)
#define MOCK_CONST_METHOD15_T_WITH_CALLTYPE(ct, m, ...) \
    GMOCK_METHOD15_(typename, const, ct, m, __VA_ARGS__)
    }
}

#endif