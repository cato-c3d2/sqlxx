/*!
 * @file table.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__TABLE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__TABLE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/closure/as-closure.class.h++>
#include <sql++/identifier/table-identifier.class.h++>

#include "./data-set/table.data-set.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__identifier)

BOOST_AUTO_TEST_SUITE(class__Table)

using sqlxx::closure::AsClosure;
using sqlxx::identifier::TableIdentifier;
using sqlxx::test::TableDataSet;

/*!
 * @brief テストパターン :
 *        @c TableIdentifier オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::identifier::TableIdentifier テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    TableIdentifier const source      = {};                              // コピー元のオブジェクト
    TableIdentifier       destination = { "people", AsClosure { "p" } }; // コピー先のオブジェクト
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
 *        様々な @c TableIdentifier オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::identifier::TableIdentifier           テスト対象クラス
 * @see sqlxx::identifier::TableIdentifier::empty()  テスト対象メンバ関数
 * @see TableDataSet::for_some_test_case()           データセット生成メンバ関数
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(TableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    TableIdentifier const table = data_set_element.table;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(table.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c TableIdentifier オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::identifier::TableIdentifier              テスト対象クラス
 * @see sqlxx::identifier::TableIdentifier::to_string() テスト対象メンバ関数
 * @see TableDataSet::for_some_test_case()              データセット生成メンバ関数
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(TableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    TableIdentifier const table = data_set_element.table;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(table.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__Table */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__identifier */)

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__TABLE_CLASS_TEST_CASE_HXX */
