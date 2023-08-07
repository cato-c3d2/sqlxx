/*!
 * @file test-module.c++
 */

/*!
 * @brief sql++ のテストモジュール
 */
#define BOOST_TEST_MODULE sqlxx

#ifdef LINK_BOOST_TEST_AS_STATIC_LIBRARY
    // Boost.Test を静的ライブラリとして使用する
    #include <boost/test/unit_test.hpp>
#else
    // Boost.Test をヘッダオンリーライブラリとして使用する
    #include <boost/test/included/unit_test.hpp>
#endif

#include "./include/sql++.test-case.h++"
