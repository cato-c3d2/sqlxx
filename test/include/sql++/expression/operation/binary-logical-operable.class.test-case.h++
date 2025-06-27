/*!
 * @file binary-logical-operable.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__BINARY_LOGICAL_OPERABLE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__BINARY_LOGICAL_OPERABLE_CLASS_TEST_CASE_HXX

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/operation/binary-logical-operable.class.h++>

#include "./data-set/binary-logical-operable-data-set.class.h++"
#include "./mock/binary-logical-operable-mock.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__BinaryLogicalOperable)

using sqlxx::BinaryLogicalOperable;
using sqlxx::test::BinaryLogicalOperableDataSet;
using sqlxx::test::BinaryLogicalOperableMock;

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::BinaryLogicalOperable                テスト対象クラス
 * @see sqlxx::expression::BinaryLogicalOperable::logical_and() テスト対象メンバ関数
 * @see BinaryLogicalOperableDataSet::for_some_test_case()      データセット
 * @see BinaryLogicalOperableMock                               テスト対象クラスを継承したモッククラス
 */
BOOST_DATA_TEST_CASE(
    logical_and,
    boost::unit_test::data::make(
        BinaryLogicalOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    BinaryLogicalOperableMock const object = data_set_element.object;

    // テスト対象メンバ関数の引数
    BinaryLogicalOperableMock const argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    BinaryLogicalOperableMock const expectation =
        data_set_element.expectation_of_logical_and;

    // テスト対象メンバ関数の実行結果
    BinaryLogicalOperableMock const actual = object.logical_and(argument);

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] evaluate メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.evaluate(), expectation.evaluate());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::BinaryLogicalOperable               テスト対象クラス
 * @see sqlxx::expression::BinaryLogicalOperable::logical_or() テスト対象メンバ関数
 * @see BinaryLogicalOperableDataSet::for_some_test_case()     データセット
 * @see BinaryLogicalOperableMock                              テスト対象クラスを継承したモッククラス
 */
BOOST_DATA_TEST_CASE(
    logical_or,
    boost::unit_test::data::make(
        BinaryLogicalOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    BinaryLogicalOperableMock const object = data_set_element.object;

    // テスト対象メンバ関数の引数
    BinaryLogicalOperableMock const argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    BinaryLogicalOperableMock const expectation =
        data_set_element.expectation_of_logical_or;

    // テスト対象メンバ関数の実行結果
    BinaryLogicalOperableMock const actual = object.logical_or(argument);

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] evaluate メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.evaluate(), expectation.evaluate());
}

BOOST_AUTO_TEST_SUITE_END(/* class__BinaryLogicalOperable */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__BINARY_LOGICAL_OPERABLE_CLASS_TEST_CASE_HXX */
