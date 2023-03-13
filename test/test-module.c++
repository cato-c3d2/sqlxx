#define BOOST_TEST_MODULE sqlxx

#ifdef LINK_BOOST_TEST_AS_STATIC_LIBRARY
    // Boost.Test を静的ライブラリとして使用する
    #include <boost/test/unit_test.hpp>
#else
    // Boost.Test をヘッダオンリーライブラリとして使用する
    #include <boost/test/included/unit_test.hpp>
#endif

// clang-format off
#include "./include/sqlxx/identifier/column.class.test-case.h++"
#include "./include/sqlxx/identifier/table.class.test-case.h++"
#include "./include/sqlxx/identifier/naming-rule.class.test-case.h++"
#include "./include/sqlxx/closure/as-closure.class.test-case.h++"
#include "./include/sqlxx/closure/select-closure.class.test-case.h++"
#include "./include/sqlxx/closure/from-closure.class.test-case.h++"
#include "./include/sqlxx/statement/select-statement.class.test-case.h++"
// clang-format on
