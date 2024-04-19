/*!
 * @file grouped-expression.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__GROUPED_EXPRESSION_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__GROUPED_EXPRESSION_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>

#include "./data-set/grouped-expression-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__GroupedExpression)

using sqlxx::Expression;
using sqlxx::GroupedExpression;
using sqlxx::IdentifierExpression;
using sqlxx::test::GroupedExpressionDataSet;

/*!
 * @brief テストパターン :
 *        @c GroupedExpression オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::expression::GroupedExpression テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    GroupedExpression const source      = {}; // コピー元のオブジェクト
    GroupedExpression       destination = {   // コピー先のオブジェクト
        GroupedExpression { IdentifierExpression { "p.id" }.equal_to(1234) }
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
 *        @c const な @c GroupedExpression オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::GroupedExpression          テスト対象クラス
 * @see sqlxx::expression::GroupedExpression::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_constant)
{
    // 複製元のオブジェクト
    Expression const * source = new GroupedExpression {
        IdentifierExpression { "p.id" }.equal_to(1234)
    };

    // 複製元のオブジェクトを複製し、複製先のオブジェクトへ代入する
    Expression const * destination = source->clone();

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source->evaluate() == destination->evaluate());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        非 @c const な @c GroupedExpression オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::GroupedExpression          テスト対象クラス
 * @see sqlxx::expression::GroupedExpression::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_non_constant)
{
    // 複製元のオブジェクト
    Expression * source = new GroupedExpression {
        IdentifierExpression { "p.id" }.equal_to(1234)
    };

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
 *        様々な @c GroupedExpression オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::expression::GroupedExpression           テスト対象クラス
 * @see sqlxx::expression::GroupedExpression::empty()  テスト対象メンバ関数
 * @see GroupedExpressionDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(
        GroupedExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    GroupedExpression const grouped_expression =
        data_set_element.grouped_expression;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = grouped_expression.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c GroupedExpression オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::GroupedExpression              テスト対象クラス
 * @see sqlxx::expression::GroupedExpression::to_string() テスト対象メンバ関数
 * @see GroupedExpressionDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(
        GroupedExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    GroupedExpression const grouped_expression =
        data_set_element.grouped_expression;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = grouped_expression.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__GroupedExpression */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__GROUPED_EXPRESSION_CLASS_TEST_CASE_HXX */
