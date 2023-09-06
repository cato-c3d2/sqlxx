/*!
 * @file as-closure.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__AS_CLOSURE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__AS_CLOSURE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/closure/as-closure.class.h++>

#include "./data-set/as-closure-data-set.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__AsClosure)

using sqlxx::closure::AsClosure;
using sqlxx::test::AsClosureDataSet;

/*!
 * @brief テストパターン :
 *        @c AsClosure オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::closure::AsClosure テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    AsClosure const source      = {};         // コピー元のオブジェクト
    AsClosure       destination = { "p.id" }; // コピー先のオブジェクト
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
 *        様々な @c AsClosure オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::closure::AsClosure              テスト対象クラス
 * @see sqlxx::closure::AsClosure::empty()     テスト対象メンバ関数
 * @see AsClosureDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(AsClosureDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    AsClosure const as_closure = data_set_element.as_closure;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(as_closure.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c AsClosure オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::closure::AsClosure              テスト対象クラス
 * @see sqlxx::closure::AsClosure::to_string() テスト対象メンバ関数
 * @see AsClosureDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(AsClosureDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    AsClosure const as_closure = data_set_element.as_closure;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(as_closure.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__AsClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__AS_CLOSURE_CLASS_TEST_CASE_HXX */
