/*!
 * @file column-identifier.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__COLUMN_IDENTIFIER_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__COLUMN_IDENTIFIER_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/clause/as-clause.class.h++>
#include <sql++/identifier/column-identifier.class.h++>

#include "./data-set/column-identifier-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__identifier)

BOOST_AUTO_TEST_SUITE(class__Column)

using sqlxx::AsClause;
using sqlxx::ColumnIdentifier;
using sqlxx::test::ColumnIdentifierDataSet;

/*!
 * @brief テストパターン :
 *        @c ColumnIdentifier オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::identifier::ColumnIdentifier テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    ColumnIdentifier const source      = {};                            // コピー元のオブジェクト
    ColumnIdentifier       destination = { "id", AsClause { "p.id" } }; // コピー先のオブジェクト
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
 *        様々な @c ColumnIdentifier オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::identifier::ColumnIdentifier           テスト対象クラス
 * @see sqlxx::identifier::ColumnIdentifier::empty()  テスト対象メンバ関数
 * @see ColumnIdentifierDataSet::for_some_test_case() データセット生成メンバ関数
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(ColumnIdentifierDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ColumnIdentifier const column = data_set_element.column;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(column.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c ColumnIdentifier オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::identifier::ColumnIdentifier              テスト対象クラス
 * @see sqlxx::identifier::ColumnIdentifier::to_string() テスト対象メンバ関数
 * @see ColumnIdentifierDataSet::for_some_test_case()    データセット生成メンバ関数
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(ColumnIdentifierDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ColumnIdentifier const column = data_set_element.column;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(column.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__Column */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__identifier */)

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__COLUMN_IDENTIFIER_CLASS_TEST_CASE_HXX */
