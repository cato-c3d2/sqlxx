/*!
 * @file identifier-expression.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/identifier-expression.class.h++>

#include "./data-set/identifier-expression-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__IdentifierExpression)

using sqlxx::Expression;
using sqlxx::IdentifierExpression;
using sqlxx::test::IdentifierExpressionDataSet;

/*!
 * @brief テストパターン :
 *        @c IdentifierExpression オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::expression::IdentifierExpression テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    IdentifierExpression const source      = {}; // コピー元のオブジェクト
    IdentifierExpression       destination = {   // コピー先のオブジェクト
        "p.id"
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
 *        @c const な @c IdentifierExpression オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::IdentifierExpression          テスト対象クラス
 * @see sqlxx::expression::IdentifierExpression::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_constant)
{
    // 複製元のオブジェクト
    Expression const * source = new IdentifierExpression { "p.id" };

    // 複製元のオブジェクトを複製し、複製先のオブジェクトへ代入する
    Expression const * destination = source->clone();

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source->evaluate() == destination->evaluate());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        非 @c const な @c IdentifierExpression オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::IdentifierExpression          テスト対象クラス
 * @see sqlxx::expression::IdentifierExpression::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_non_constant)
{
    // 複製元のオブジェクト
    Expression * source = new IdentifierExpression { "p.id" };

    // 複製先のオブジェクト
    // FIXME [要不具合修正] コンパイルエラーが発生する。
    //       非 const オブジェクトへの複製と代入ができるように修正すること。
    // Expression * destination = nullptr;
    Expression const * destination = nullptr;

    // 複製元のオブジェクトを複製し、複製先のオブジェクトへ代入する
    destination = source->clone();

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source->evaluate() == destination->evaluate());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        様々な @c IdentifierExpression オブジェクトに対して @c name メンバ関数を呼び出す
 *
 * @see sqlxx::expression::IdentifierExpression           テスト対象クラス
 * @see sqlxx::expression::IdentifierExpression::name()   テスト対象メンバ関数
 * @see IdentifierExpressionDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    name,
    boost::unit_test::data::make(
        IdentifierExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    IdentifierExpression const identifier_expression =
        data_set_element.identifier_expression;

    // テスト対象メンバ関数の期待結果
    std::string const expectation =
        data_set_element.expectation_of_name_and_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = identifier_expression.name();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c IdentifierExpression オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::IdentifierExpression              テスト対象クラス
 * @see sqlxx::expression::IdentifierExpression::to_string() テスト対象メンバ関数
 * @see IdentifierExpressionDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(
        IdentifierExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    IdentifierExpression const identifier_expression =
        data_set_element.identifier_expression;

    // テスト対象メンバ関数の期待結果
    std::string const expectation =
        data_set_element.expectation_of_name_and_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = identifier_expression.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__IdentifierExpression */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_TEST_CASE_HXX */
