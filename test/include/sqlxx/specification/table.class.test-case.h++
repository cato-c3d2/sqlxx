/*!
 * @file table.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__TABLE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__TABLE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/specification/table.class.h++>

#include "./data-set/table.data-set.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__Table)

using sqlxx::specification::Table;

/*!
 * @brief テストパターン :
 *        @c Table オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::specification::Table
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    Table const source      = {};                // コピー元のオブジェクト
    Table       destination = { "people", "p" }; // コピー先のオブジェクト
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
 *        様々な @c Table オブジェクトに対して SQL 文字列を生成する
 *
 * @see sqlxx::specification::Table
 * @see sqlxx::specification::Table::to_string()
 * @see data_set_for_to_string()
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(data_set_for_to_string()),
    data_set_element)
{
    // テスト対象オブジェクト
    Table const table = data_set_element.table;

    // 生成される SQL 文字列の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象オブジェクトから生成された SQL 文字列が期待結果と一致すること
    BOOST_CHECK_EQUAL(table.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__Table */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__TABLE_CLASS_TEST_CASE_HXX */
