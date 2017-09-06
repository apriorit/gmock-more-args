#pragma once
#include <gmock/internal/gmock-port.h>

namespace testing
{
    template <typename T>
    class Matcher;

    namespace internal 
    {
        template <typename Tuple>
        struct MatcherTuple;

        //
        // Definitions for 11 arguments
        //
        template <typename A1, typename A2, typename A3, typename A4, typename A5,
            typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
            struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
            A10, A11> > {
            typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8>, Matcher<A9>,
                Matcher<A10>, Matcher<A11> > type;
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11>
            struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)>
            : Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)> {
            typedef A11 Argument11;
            typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
                A10, A11> ArgumentTuple;
            typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
            typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11);
            typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8,
                A9, A10, A11);
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11>
            class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)> : public
            internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)> {
            public:
                typedef R F(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11);
                typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

                MockSpec<F>& With(const Matcher<A1>& m1, const Matcher<A2>& m2,
                    const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
                    const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8,
                    const Matcher<A9>& m9, const Matcher<A10>& m10, const Matcher<A11>& m11) {
                    this->current_spec().SetMatchers(::testing::make_tuple(m1, m2, m3, m4, m5,
                        m6, m7, m8, m9, m10, m11));
                    return this->current_spec();
                }

                R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9,
                    A10 a10, A11 a11) {
                    // Even though gcc and MSVC don't enforce it, 'this->' is required
                    // by the C++ standard [14.6.4] here, as the base class type is
                    // dependent on the template argument (and thus shouldn't be
                    // looked into when resolving InvokeWith).
                    return this->InvokeWith(ArgumentTuple(a1, a2, a3, a4, a5, a6, a7, a8, a9,
                        a10, a11));
                }
        };


#define GMOCK_METHOD11_(tn, constness, ct, Method, ...) \
        GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10,\
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 11), \
        this_method_does_not_take_11_arguments); \
    GMOCK_MOCKER_(11, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(11, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, \
                         __VA_ARGS__) gmock_a11) constness { \
    GMOCK_MOCKER_(11, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(11, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11); \
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
        template <typename A1, typename A2, typename A3, typename A4, typename A5,
            typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
            struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
            A10, A11, A12> > {
            typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8>, Matcher<A9>,
                Matcher<A10>, Matcher<A11>, Matcher<A12>> type;
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12>
            struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)>
            : Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)> {
            typedef A12 Argument12;
            typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
                A10, A11, A12> ArgumentTuple;
            typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
            typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12);
            typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8,
                A9, A10, A11, A12);
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12>
            class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)> : public
            internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)> {
            public:
                typedef R F(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12);
                typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

                MockSpec<F>& With(const Matcher<A1>& m1, const Matcher<A2>& m2,
                    const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
                    const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8,
                    const Matcher<A9>& m9, const Matcher<A10>& m10, const Matcher<A11>& m11
                    , const Matcher<A12>& m12) {
                    this->current_spec().SetMatchers(::testing::make_tuple(m1, m2, m3, m4, m5,
                        m6, m7, m8, m9, m10, m11, m12));
                    return this->current_spec();
                }

                R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9,
                    A10 a10, A11 a11, A12 a12) {
                    // Even though gcc and MSVC don't enforce it, 'this->' is required
                    // by the C++ standard [14.6.4] here, as the base class type is
                    // dependent on the template argument (and thus shouldn't be
                    // looked into when resolving InvokeWith).
                    return this->InvokeWith(ArgumentTuple(a1, a2, a3, a4, a5, a6, a7, a8, a9,
                        a10, a11, a12));
                }
        };


#define GMOCK_METHOD12_(tn, constness, ct, Method, ...) \
        GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10,\
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 12), \
        this_method_does_not_take_12_arguments); \
    GMOCK_MOCKER_(12, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(12, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, \
                         __VA_ARGS__) gmock_a12) constness { \
    GMOCK_MOCKER_(12, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(12, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12); \
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
        template <typename A1, typename A2, typename A3, typename A4, typename A5,
            typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
            struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
            A10, A11, A12, A13> > {
            typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8>, Matcher<A9>,
                Matcher<A10>, Matcher<A11>, Matcher<A12>, Matcher<A13>> type;
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12, typename A13>
            struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)>
            : Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)> {
            typedef A13 Argument13;
            typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
                A10, A11, A12, A13> ArgumentTuple;
            typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
            typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13);
            typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8,
                A9, A10, A11, A12, A13);
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12, typename A13>
            class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)> : public
            internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)> {
            public:
                typedef R F(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13);
                typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

                MockSpec<F>& With(const Matcher<A1>& m1, const Matcher<A2>& m2,
                    const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
                    const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8,
                    const Matcher<A9>& m9, const Matcher<A10>& m10, const Matcher<A11>& m11
                    , const Matcher<A12>& m12, const Matcher<A13>& m13) {
                    this->current_spec().SetMatchers(::testing::make_tuple(m1, m2, m3, m4, m5,
                        m6, m7, m8, m9, m10, m11, m12, m13));
                    return this->current_spec();
                }

                R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9,
                    A10 a10, A11 a11, A12 a12, A13 a13) {
                    // Even though gcc and MSVC don't enforce it, 'this->' is required
                    // by the C++ standard [14.6.4] here, as the base class type is
                    // dependent on the template argument (and thus shouldn't be
                    // looked into when resolving InvokeWith).
                    return this->InvokeWith(ArgumentTuple(a1, a2, a3, a4, a5, a6, a7, a8, a9,
                        a10, a11, a12, a13));
                }
        };


#define GMOCK_METHOD13_(tn, constness, ct, Method, ...) \
        GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10,\
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 13), \
        this_method_does_not_take_13_arguments); \
    GMOCK_MOCKER_(13, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(13, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, __VA_ARGS__) gmock_a12, \
                     GMOCK_MATCHER_(tn, 13, \
                         __VA_ARGS__) gmock_a13) constness { \
    GMOCK_MOCKER_(13, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(13, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13); \
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
        template <typename A1, typename A2, typename A3, typename A4, typename A5,
            typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
            struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
            A10, A11, A12, A13, A14> > {
            typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8>, Matcher<A9>,
                Matcher<A10>, Matcher<A11>, Matcher<A12>, Matcher<A13>, Matcher<A14>> type;
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12, typename A13, typename A14>
            struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)>
            : Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)> {
            typedef A14 Argument14;
            typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
                A10, A11, A12, A13, A14> ArgumentTuple;
            typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
            typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14);
            typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8,
                A9, A10, A11, A12, A13, A14);
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12, typename A13, typename A14>
            class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)> : public
            internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)> {
            public:
                typedef R F(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14);
                typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

                MockSpec<F>& With(const Matcher<A1>& m1, const Matcher<A2>& m2,
                    const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
                    const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8,
                    const Matcher<A9>& m9, const Matcher<A10>& m10, const Matcher<A11>& m11
                    , const Matcher<A12>& m12, const Matcher<A13>& m13, const Matcher<A14>& m14) {
                    this->current_spec().SetMatchers(::testing::make_tuple(m1, m2, m3, m4, m5,
                        m6, m7, m8, m9, m10, m11, m12, m13, m14));
                    return this->current_spec();
                }

                R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9,
                    A10 a10, A11 a11, A12 a12, A13 a13, A14 a14) {
                    // Even though gcc and MSVC don't enforce it, 'this->' is required
                    // by the C++ standard [14.6.4] here, as the base class type is
                    // dependent on the template argument (and thus shouldn't be
                    // looked into when resolving InvokeWith).
                    return this->InvokeWith(ArgumentTuple(a1, a2, a3, a4, a5, a6, a7, a8, a9,
                        a10, a11, a12, a13, a14));
                }
        };


#define GMOCK_METHOD14_(tn, constness, ct, Method, ...) \
        GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10,\
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
      GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 14), \
        this_method_does_not_take_14_arguments); \
    GMOCK_MOCKER_(14, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(14, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, __VA_ARGS__) gmock_a12, \
                     GMOCK_MATCHER_(tn, 13, __VA_ARGS__) gmock_a13, \
                     GMOCK_MATCHER_(tn, 14, \
                         __VA_ARGS__) gmock_a14) constness { \
    GMOCK_MOCKER_(14, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(14, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14); \
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
        template <typename A1, typename A2, typename A3, typename A4, typename A5,
            typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, 
            typename A12, typename A13, typename A14, typename A15>
            struct MatcherTuple< ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
            A10, A11, A12, A13, A14, A15> > {
            typedef ::testing::tuple<Matcher<A1>, Matcher<A2>, Matcher<A3>, Matcher<A4>,
                Matcher<A5>, Matcher<A6>, Matcher<A7>, Matcher<A8>, Matcher<A9>,
                Matcher<A10>, Matcher<A11>, Matcher<A12>, Matcher<A13>, Matcher<A14>, Matcher<A15>> type;
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
            struct Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15)>
            : Function<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)> {
            typedef A15 Argument15;
            typedef ::testing::tuple<A1, A2, A3, A4, A5, A6, A7, A8, A9,
                A10, A11, A12, A13, A14, A15> ArgumentTuple;
            typedef typename MatcherTuple<ArgumentTuple>::type ArgumentMatcherTuple;
            typedef void MakeResultVoid(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15);
            typedef IgnoredValue MakeResultIgnoredValue(A1, A2, A3, A4, A5, A6, A7, A8,
                A9, A10, A11, A12, A13, A14, A15);
        };

        template <typename R, typename A1, typename A2, typename A3, typename A4,
            typename A5, typename A6, typename A7, typename A8, typename A9,
            typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
            class FunctionMocker<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15)> : public
            internal::FunctionMockerBase<R(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15)> {
            public:
                typedef R F(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15);
                typedef typename internal::Function<F>::ArgumentTuple ArgumentTuple;

                MockSpec<F>& With(const Matcher<A1>& m1, const Matcher<A2>& m2,
                    const Matcher<A3>& m3, const Matcher<A4>& m4, const Matcher<A5>& m5,
                    const Matcher<A6>& m6, const Matcher<A7>& m7, const Matcher<A8>& m8,
                    const Matcher<A9>& m9, const Matcher<A10>& m10, const Matcher<A11>& m11,
                    const Matcher<A12>& m12, const Matcher<A13>& m13, const Matcher<A14>& m14,
                    const Matcher<A14>& m15) {
                    this->current_spec().SetMatchers(::testing::make_tuple(m1, m2, m3, m4, m5,
                        m6, m7, m8, m9, m10, m11, m12, m13, m14, m15));
                    return this->current_spec();
                }

                R Invoke(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9,
                    A10 a10, A11 a11, A12 a12, A13 a13, A14 a14, A15 a15) {
                    // Even though gcc and MSVC don't enforce it, 'this->' is required
                    // by the C++ standard [14.6.4] here, as the base class type is
                    // dependent on the template argument (and thus shouldn't be
                    // looked into when resolving InvokeWith).
                    return this->InvokeWith(ArgumentTuple(a1, a2, a3, a4, a5, a6, a7, a8, a9,
                        a10, a11, a12, a13, a14, a15));
                }
        };


#define GMOCK_METHOD15_(tn, constness, ct, Method, ...) \
        GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10,\
      GMOCK_ARG_(tn, 11, __VA_ARGS__) gmock_a11, \
      GMOCK_ARG_(tn, 12, __VA_ARGS__) gmock_a12, \
      GMOCK_ARG_(tn, 13, __VA_ARGS__) gmock_a13, \
      GMOCK_ARG_(tn, 14, __VA_ARGS__) gmock_a14, \
      GMOCK_ARG_(tn, 15, __VA_ARGS__) gmock_a15) constness { \
    GTEST_COMPILE_ASSERT_((::testing::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 15), \
        this_method_does_not_take_15_arguments); \
    GMOCK_MOCKER_(15, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(15, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14, gmock_a15); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, __VA_ARGS__) gmock_a10, \
                     GMOCK_MATCHER_(tn, 11, __VA_ARGS__) gmock_a11, \
                     GMOCK_MATCHER_(tn, 12, __VA_ARGS__) gmock_a12, \
                     GMOCK_MATCHER_(tn, 13, __VA_ARGS__) gmock_a13, \
                     GMOCK_MATCHER_(tn, 14, __VA_ARGS__) gmock_a14, \
                     GMOCK_MATCHER_(tn, 15, \
                         __VA_ARGS__) gmock_a15) constness { \
    GMOCK_MOCKER_(15, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(15, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10, gmock_a11, gmock_a12, gmock_a13, gmock_a14, gmock_a15); \
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