/*!
 * @file select-statement.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/specification/column.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "./data-set/select-statement.data-set-element.class.h++"
#include "./data-set/select-statement.data-set.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__statement)

BOOST_AUTO_TEST_SUITE(class__SelectStatement)

using sqlxx::closure::FromClosure;
using sqlxx::closure::SelectClosure;
using sqlxx::specification::Column;
using sqlxx::specification::Table;
using sqlxx::statement::SelectStatement;

/*!
 * @brief テストパターン :
 *        @c SelectStatement オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::statement::SelectStatement
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    SelectStatement const source      = {}; // コピー元のオブジェクト
    SelectStatement       destination = {   // コピー先のオブジェクト
        SelectClosure {
            Column { "p", "p.id" },
            Column { "name", "p.name" }
        },
        FromClosure { Table { "people", "p" } }
    };
    // clang-format on

    // 二つのオブジェクトは等価ではないこと
    BOOST_CHECK(source.to_string() != destination.to_string());

    // コピー元のオブジェクトをコピー先のオブジェクトをコピー代入する
    destination = source;

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source.to_string() == destination.to_string());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        様々な @c SelectStatement オブジェクトに対して SQL 文字列を生成する
 *
 * @see sqlxx::statement::SelectStatement
 * @see sqlxx::statement::SelectStatement::to_string()
 * @see data_set_for_to_string()
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(data_set_for_to_string()),
    data_set_element)
{
    // テスト対象オブジェクト
    SelectStatement const select_statement = data_set_element.select_statement;

    // 生成される SQL 文字列の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象オブジェクトから生成された SQL 文字列が期待結果と一致すること
    BOOST_CHECK_EQUAL(select_statement.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_TEST_CASE_HXX */