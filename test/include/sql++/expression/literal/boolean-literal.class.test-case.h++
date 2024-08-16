/*!
 * @file boolean-literal.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__BOOLEAN_LITERAL_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__BOOLEAN_LITERAL_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/literal/boolean-literal.class.h++>

#include "./data-set/boolean-literal-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__BooleanLiteral)

using sqlxx::BooleanLiteral;
using sqlxx::Expression;
using sqlxx::test::BooleanLiteralDataSet;

/*!
 * @brief テストパターン :
 *        @c BooleanLiteral オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::expression::BooleanLiteral テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    BooleanLiteral const source      = {}; // コピー元のオブジェクト
    BooleanLiteral       destination = {   // コピー先のオブジェクト
        true
    };
    // clang-format on

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
 *        @c const な @c BooleanLiteral オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::BooleanLiteral          テスト対象クラス
 * @see sqlxx::expression::BooleanLiteral::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_constant)
{
    // 複製元のオブジェクト
    Expression const * source = new BooleanLiteral { false };

    // 複製元のオブジェクトを複製し、複製先のオブジェクトへ代入する
    Expression const * destination = source->clone();

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source->evaluate() == destination->evaluate());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        非 @c const な @c BooleanLiteral オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::BooleanLiteral          テスト対象クラス
 * @see sqlxx::expression::BooleanLiteral::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_non_constant)
{
    // 複製元のオブジェクト
    Expression * source = new BooleanLiteral { false };

    // 複製先のオブジェクト
    Expression * destination = nullptr;

    // 複製元のオブジェクトを複製し、複製先のオブジェクトへ代入する
    destination = source->clone();

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source->evaluate() == destination->evaluate());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        様々な @c BooleanLiteral オブジェクトに対して @c inner_value メンバ関数を呼び出す
 *
 * @see sqlxx::expression::BooleanLiteral                テスト対象クラス
 * @see sqlxx::expression::BooleanLiteral::inner_value() テスト対象メンバ関数
 * @see BooleanLiteralDataSet::for_some_test_case()      データセット
 */
BOOST_DATA_TEST_CASE(
    inner_value,
    boost::unit_test::data::make(BooleanLiteralDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    BooleanLiteral const boolean_literal = data_set_element.boolean_literal;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_inner_value;

    // テスト対象メンバ関数の実行結果
    bool const actual = boolean_literal.inner_value();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c BooleanLiteral オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::BooleanLiteral              テスト対象クラス
 * @see sqlxx::expression::BooleanLiteral::to_string() テスト対象メンバ関数
 * @see BooleanLiteralDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(BooleanLiteralDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    BooleanLiteral const boolean_literal = data_set_element.boolean_literal;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = boolean_literal.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__BooleanLiteral */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__BOOLEAN_LITERAL_CLASS_TEST_CASE_HXX */
