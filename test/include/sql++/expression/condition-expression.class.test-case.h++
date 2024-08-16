/*!
 * @file condition-expression.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>

#include "./data-set/condition-expression-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__ConditionExpression)

using sqlxx::ConditionExpression;
using sqlxx::Expression;
using sqlxx::IdentifierExpression;
using sqlxx::test::ConditionExpressionDataSet;

/*!
 * @brief テストパターン :
 *        @c ConditionExpression オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::expression::ConditionExpression テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    ConditionExpression const source      = {}; // コピー元のオブジェクト
    ConditionExpression       destination = {   // コピー先のオブジェクト
        IdentifierExpression { "p.id" }.equal_to(1234)
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
 *        @c const な @c ConditionExpression オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::ConditionExpression          テスト対象クラス
 * @see sqlxx::expression::ConditionExpression::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_constant)
{
    // 複製元のオブジェクト
    Expression const * source = new ConditionExpression {
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
 *        非 @c const な @c ConditionExpression オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::ConditionExpression          テスト対象クラス
 * @see sqlxx::expression::ConditionExpression::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_non_constant)
{
    // 複製元のオブジェクト
    Expression * source = new ConditionExpression {
        IdentifierExpression { "p.id" }.equal_to(1234)
    };

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
 *        非 DSL 記法で構築した @c ConditionExpression オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::expression::ConditionExpression           テスト対象クラス
 * @see sqlxx::expression::ConditionExpression::empty()  テスト対象メンバ関数
 * @see ConditionExpressionDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty_as_non_dsl,
    boost::unit_test::data::make(
        ConditionExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト - 非DSL記法
    ConditionExpression const condition_expression =
        data_set_element.condition_expression;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = condition_expression.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        DSL 記法で構築した @c ConditionExpression オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::expression::ConditionExpression           テスト対象クラス
 * @see sqlxx::expression::ConditionExpression::empty()  テスト対象メンバ関数
 * @see ConditionExpressionDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty_as_dsl,
    boost::unit_test::data::make(
        ConditionExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    if (! data_set_element.condition_expression_as_dsl) {
        // DSL 記法のテスト対象オブジェクトが設定されていない場合
        // 本テストケースは実施しない
        return;
    }

    // テスト対象オブジェクト - DSL記法
    ConditionExpression const condition_expression =
        data_set_element.condition_expression_as_dsl.value();

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = condition_expression.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        非 DSL 記法で構築した @c ConditionExpression オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::ConditionExpression              テスト対象クラス
 * @see sqlxx::expression::ConditionExpression::to_string() テスト対象メンバ関数
 * @see ConditionExpressionDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string_as_non_dsl,
    boost::unit_test::data::make(
        ConditionExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト - 非DSL記法
    ConditionExpression const condition_expression =
        data_set_element.condition_expression;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = condition_expression.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        DSL 記法で構築した @c ConditionExpression オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::ConditionExpression              テスト対象クラス
 * @see sqlxx::expression::ConditionExpression::to_string() テスト対象メンバ関数
 * @see ConditionExpressionDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string_as_dsl,
    boost::unit_test::data::make(
        ConditionExpressionDataSet::for_some_test_case()),
    data_set_element)
{
    if (! data_set_element.condition_expression_as_dsl) {
        // DSL 記法のテスト対象オブジェクトが設定されていない場合
        // 本テストケースは実施しない
        return;
    }

    // テスト対象オブジェクト - DSL記法
    ConditionExpression const condition_expression =
        data_set_element.condition_expression_as_dsl.value();

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = condition_expression.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__ConditionExpression */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_TEST_CASE_HXX */
