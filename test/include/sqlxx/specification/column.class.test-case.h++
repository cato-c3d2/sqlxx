/*!
 * @file column.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__COLUMN_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__COLUMN_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/specification/column.class.h++>

#include "./data-set/column.data-set.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__Column)

using sqlxx::specification::Column;

/*!
 * @brief テストパターン :
 *        @c Column オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::specification::Column
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    Column const source      = {};               // コピー元のオブジェクト
    Column       destination = { "id", "p.id" }; // コピー先のオブジェクト
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
 *        様々な @c Column オブジェクトを構築し, @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::specification::Column
 * @see sqlxx::specification::Column::empty()
 * @see data_set()
 */
BOOST_DATA_TEST_CASE(
    empty, boost::unit_test::data::make(data_set()), data_set_element)
{
    // テスト対象オブジェクト
    Column const column = data_set_element.column;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(column.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c Column オブジェクトに対して SQL 文字列を生成する
 *
 * @see sqlxx::specification::Column
 * @see sqlxx::specification::Column::to_string()
 * @see data_set()
 */
BOOST_DATA_TEST_CASE(
    to_string, boost::unit_test::data::make(data_set()), data_set_element)
{
    // テスト対象オブジェクト
    Column const column = data_set_element.column;

    // 生成される SQL 文字列の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象オブジェクトから生成された SQL 文字列が期待結果と一致すること
    BOOST_CHECK_EQUAL(column.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__Column */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__COLUMN_CLASS_TEST_CASE_HXX */
