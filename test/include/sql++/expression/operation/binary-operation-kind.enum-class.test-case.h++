/*!
 * @file binary-operation-kind.enum-class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__BINARY_OPERATION_KIND_ENUM_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__BINARY_OPERATION_KIND_ENUM_CLASS_TEST_CASE_HXX

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>

#include "./data-set/binary-operation-kind-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(enum__class__OperationKind)

using sqlxx::BinaryOperationKind;
using sqlxx::test::BinaryOperationKindDataSet;

/*!
 * @brief テストパターン :
 *        様々な @c BinaryOperationKind オブジェクトを引数として @c to_string 関数を呼び出す
 *
 * @see sqlxx::expression::BinaryOperationKind           テスト対象列挙型
 * @see sqlxx::expression::to_string()                   テスト対象関数
 * @see BinaryOperationKindDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(
        BinaryOperationKindDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    BinaryOperationKind const binary_operation_kind =
        data_set_element.binary_operation_kind;

    // テスト対象関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象関数の実行結果
    std::string const actual =
        sqlxx::expression::to_string(binary_operation_kind);

    // テスト対象関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* enum__class__OperationKind */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__BINARY_OPERATION_KIND_ENUM_CLASS_TEST_CASE_HXX */
