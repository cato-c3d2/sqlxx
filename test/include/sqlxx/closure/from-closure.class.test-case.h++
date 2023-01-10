/*!
 * @file from-closure.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__FROM_CLOSURE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__FROM_CLOSURE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/specification/table.class.h++>

#include "./data-set/from-closure.data-set.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__FromClosure)

using sqlxx::closure::FromClosure;
using sqlxx::specification::Table;

/*!
 * @brief テストパターン :
 *        @c FromClosure オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::closure::FromClosure
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    FromClosure const source      = {}; // コピー元のオブジェクト
    FromClosure       destination = {   // コピー先のオブジェクト
        Table { "people", "p" }};
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
 *        様々な @c FromClosure オブジェクトを構築し, @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::closure::FromClosure
 * @see sqlxx::closure::FromClosure::empty()
 * @see data_set_for_to_string()
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(data_set_for_to_string()),
    data_set_element)
{
    // テスト対象オブジェクト
    FromClosure const from_closure = data_set_element.from_closure;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(from_closure.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c FromClosure オブジェクトに対して SQL 文字列を生成する
 *
 * @see sqlxx::closure::FromClosure
 * @see sqlxx::closure::FromClosure::to_string()
 * @see data_set_for_to_string()
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(data_set_for_to_string()),
    data_set_element)
{
    // テスト対象オブジェクト
    FromClosure const from_closure = data_set_element.from_closure;

    // 生成される SQL 文字列の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象オブジェクトから生成された SQL 文字列が期待結果と一致すること
    BOOST_CHECK_EQUAL(from_closure.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__FromClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__FROM_CLOSURE_CLASS_TEST_CASE_HXX */
