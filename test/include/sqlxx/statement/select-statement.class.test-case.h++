/*!
 * @file select-statement.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "./data-set/select-statement-data-set-element.class.h++"
#include "./data-set/select-statement.data-set.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__statement)

BOOST_AUTO_TEST_SUITE(class__SelectStatement)

using sqlxx::closure::FromClosure;
using sqlxx::closure::SelectClosure;
using sqlxx::identifier::Column;
using sqlxx::identifier::Table;
using sqlxx::statement::SelectStatement;
using sqlxx::test::SelectStatementDataSet;

/*!
 * @brief テストパターン :
 *        @c SelectStatement オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::statement::SelectStatement テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    SelectStatement const source      = {}; // コピー元のオブジェクト
    SelectStatement       destination = {   // コピー先のオブジェクト
        SelectClosure {
            Column { "p" }.as({ "p.id" }),
            Column { "name" }.as({ "p.name" })
        },
        FromClosure { Table { "people" }.as({ "p" }) }
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
 *        様々な @c SelectStatement オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::statement::SelectStatement              テスト対象クラス
 * @see sqlxx::statement::SelectStatement::to_string() テスト対象メンバ関数
 * @see SelectStatementDataSet::for_some_test_case()   データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(SelectStatementDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    SelectStatement const select_statement = data_set_element.select_statement;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(select_statement.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_TEST_CASE_HXX */
