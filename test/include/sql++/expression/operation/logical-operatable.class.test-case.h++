/*!
 * @file logical-operatable.class.test-case.h++
 */

// FIXME 【要修正】ファイル名を変更する予定 : logical-operatable*.h++ => logical-operable*.h++

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__LOGICAL_OPERATABLE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__LOGICAL_OPERATABLE_CLASS_TEST_CASE_HXX

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/operation/logical-operatable.class.h++>

#include "./data-set/logical-operatable-data-set.class.h++"
#include "./mock/logical-operatable-mock.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__LogicalOperable)

using sqlxx::LogicalOperable;
using sqlxx::test::LogicalOperableDataSet;
using sqlxx::test::LogicalOperableMock;

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::LogicalOperable                テスト対象クラス
 * @see sqlxx::expression::LogicalOperable::logical_and() テスト対象メンバ関数
 * @see LogicalOperableDataSet::for_some_test_case()      データセット
 * @see LogicalOperableMock                               テスト対象クラスを継承したモッククラス
 */
BOOST_DATA_TEST_CASE(
    logical_and,
    boost::unit_test::data::make(LogicalOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    LogicalOperableMock const object = data_set_element.object;

    // テスト対象メンバ関数の引数
    LogicalOperableMock const argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    LogicalOperableMock const expectation =
        data_set_element.expectation_of_logical_and;

    // テスト対象メンバ関数の実行結果
    LogicalOperableMock const actual = object.logical_and(argument);

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] evaluate メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.evaluate(), expectation.evaluate());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::LogicalOperable               テスト対象クラス
 * @see sqlxx::expression::LogicalOperable::logical_or() テスト対象メンバ関数
 * @see LogicalOperableDataSet::for_some_test_case()     データセット
 * @see LogicalOperableMock                              テスト対象クラスを継承したモッククラス
 */
BOOST_DATA_TEST_CASE(
    logical_or,
    boost::unit_test::data::make(LogicalOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    LogicalOperableMock const object = data_set_element.object;

    // テスト対象メンバ関数の引数
    LogicalOperableMock const argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    LogicalOperableMock const expectation =
        data_set_element.expectation_of_logical_or;

    // テスト対象メンバ関数の実行結果
    LogicalOperableMock const actual = object.logical_or(argument);

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] evaluate メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.evaluate(), expectation.evaluate());
}

BOOST_AUTO_TEST_SUITE_END(/* class__LogicalOperable */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__LOGICAL_OPERATABLE_CLASS_TEST_CASE_HXX */
