/*!
 * @file real-number-literal.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__REAL_NUMBER_LITERAL_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__REAL_NUMBER_LITERAL_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/literal/real-number-literal.class.h++>

#include "./data-set/real-number-literal-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__RealNumberLiteral)

using sqlxx::Expression;
using sqlxx::RealNumberLiteral;
using sqlxx::test::RealNumberLiteralDataSet;

/*!
 * @brief テストパターン :
 *        @c RealNumberLiteral オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::expression::RealNumberLiteral テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    RealNumberLiteral const source      = {}; // コピー元のオブジェクト
    RealNumberLiteral       destination = {   // コピー先のオブジェクト
        1234.5678
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
 *        @c const な @c RealNumberLiteral オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::RealNumberLiteral          テスト対象クラス
 * @see sqlxx::expression::RealNumberLiteral::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_constant)
{
    // 複製元のオブジェクト
    Expression const * source = new RealNumberLiteral { 1234.5678 };

    // 複製元のオブジェクトを複製し、複製先のオブジェクトへ代入する
    Expression const * destination = source->clone();

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source->evaluate() == destination->evaluate());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        非 @c const な @c RealNumberLiteral オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::RealNumberLiteral          テスト対象クラス
 * @see sqlxx::expression::RealNumberLiteral::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_non_constant)
{
    // 複製元のオブジェクト
    Expression * source = new RealNumberLiteral { 1234.5678 };

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
 *        様々な @c RealNumberLiteral オブジェクトに対して @c inner_value メンバ関数を呼び出す
 *
 * @see sqlxx::expression::RealNumberLiteral                テスト対象クラス
 * @see sqlxx::expression::RealNumberLiteral::inner_value() テスト対象メンバ関数
 * @see RealNumberLiteralDataSet::for_some_test_case()      データセット
 */
BOOST_DATA_TEST_CASE(
    inner_value,
    boost::unit_test::data::make(
        RealNumberLiteralDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    RealNumberLiteral const real_number_literal =
        data_set_element.real_number_literal;

    // テスト対象メンバ関数の期待結果
    float const expectation = data_set_element.expectation_of_inner_value;

    // テスト対象メンバ関数の実行結果
    float const actual = real_number_literal.inner_value();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c RealNumberLiteral オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::RealNumberLiteral              テスト対象クラス
 * @see sqlxx::expression::RealNumberLiteral::to_string() テスト対象メンバ関数
 * @see RealNumberLiteralDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(
        RealNumberLiteralDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    RealNumberLiteral const real_number_literal =
        data_set_element.real_number_literal;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = real_number_literal.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__RealNumberLiteral */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__REAL_NUMBER_LITERAL_CLASS_TEST_CASE_HXX */
