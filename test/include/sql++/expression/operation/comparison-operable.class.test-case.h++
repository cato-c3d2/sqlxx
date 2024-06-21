/*!
 * @file comparison-operable.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__COMPARISON_OPERABLE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__COMPARISON_OPERABLE_CLASS_TEST_CASE_HXX

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/operation/comparison-operable.class.h++>

#include "./data-set/comparison-operable-data-set.class.h++"
#include "./mock/comparison-operable-mock-x.class.h++"
#include "./mock/comparison-operable-mock-y.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__ComparisonOperable)

using sqlxx::ComparisonOperable;
using sqlxx::ConditionExpression;
using sqlxx::test::ComparisonOperableDataSet;
using sqlxx::test::ComparisonOperableMockX;
using sqlxx::test::ComparisonOperableMockY;

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスX、またはモッククラスYのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::ComparisonOperable             テスト対象クラス
 * @see sqlxx::expression::ComparisonOperable::equal_to() テスト対象メンバ関数
 * @see ComparisonOperableDataSet::for_some_test_case()   データセット
 * @see ComparisonOperableMockX                           テスト対象クラスを継承したモッククラス（その一）
 * @see ComparisonOperableMockY                           テスト対象クラスを継承したモッククラス（その二）
 */
BOOST_DATA_TEST_CASE(
    equal_to,
    boost::unit_test::data::make(
        ComparisonOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ComparisonOperable const * object = data_set_element.object;

    // テスト対象メンバ関数の引数
    ComparisonOperable const * argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    ConditionExpression const expectation =
        data_set_element.expectation_of_equal_to;

    // テスト対象メンバ関数の引数となるオブジェクトの型を X または Y に変換し、
    // テスト対象メンバ関数を実行する
    ConditionExpression actual;
    if (ComparisonOperableMockX const * x =
            dynamic_cast<ComparisonOperableMockX const *>(argument);
        x != nullptr) {
        actual = object->equal_to(*x);
    } else if (ComparisonOperableMockY const * y =
                   dynamic_cast<ComparisonOperableMockY const *>(argument);
               y != nullptr) {
        actual = object->equal_to(*y);
    } else {
        BOOST_ERROR("The argument is invalid!");
    }

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] to_string メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.to_string(), expectation.to_string());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスX、またはモッククラスYのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::ComparisonOperable                 テスト対象クラス
 * @see sqlxx::expression::ComparisonOperable::not_equal_to() テスト対象メンバ関数
 * @see ComparisonOperableDataSet::for_some_test_case()       データセット
 * @see ComparisonOperableMockX                               テスト対象クラスを継承したモッククラス（その一）
 * @see ComparisonOperableMockY                               テスト対象クラスを継承したモッククラス（その二）
 */
BOOST_DATA_TEST_CASE(
    not_equal_to,
    boost::unit_test::data::make(
        ComparisonOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ComparisonOperable const * object = data_set_element.object;

    // テスト対象メンバ関数の引数
    ComparisonOperable const * argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    ConditionExpression const expectation =
        data_set_element.expectation_of_not_equal_to;

    // テスト対象メンバ関数の引数となるオブジェクトの型を X または Y に変換し、
    // テスト対象メンバ関数を実行する
    ConditionExpression actual;
    if (ComparisonOperableMockX const * x =
            dynamic_cast<ComparisonOperableMockX const *>(argument);
        x != nullptr) {
        actual = object->not_equal_to(*x);
    } else if (ComparisonOperableMockY const * y =
                   dynamic_cast<ComparisonOperableMockY const *>(argument);
               y != nullptr) {
        actual = object->not_equal_to(*y);
    } else {
        BOOST_ERROR("The argument is invalid!");
    }

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] to_string メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.to_string(), expectation.to_string());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスX、またはモッククラスYのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::ComparisonOperable           テスト対象クラス
 * @see sqlxx::expression::ComparisonOperable::less()   テスト対象メンバ関数
 * @see ComparisonOperableDataSet::for_some_test_case() データセット
 * @see ComparisonOperableMockX                         テスト対象クラスを継承したモッククラス（その一）
 * @see ComparisonOperableMockY                         テスト対象クラスを継承したモッククラス（その二）
 */
BOOST_DATA_TEST_CASE(
    less,
    boost::unit_test::data::make(
        ComparisonOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ComparisonOperable const * object = data_set_element.object;

    // テスト対象メンバ関数の引数
    ComparisonOperable const * argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    ConditionExpression const expectation =
        data_set_element.expectation_of_less;

    // テスト対象メンバ関数の引数となるオブジェクトの型を X または Y に変換し、
    // テスト対象メンバ関数を実行する
    ConditionExpression actual;
    if (ComparisonOperableMockX const * x =
            dynamic_cast<ComparisonOperableMockX const *>(argument);
        x != nullptr) {
        actual = object->less(*x);
    } else if (ComparisonOperableMockY const * y =
                   dynamic_cast<ComparisonOperableMockY const *>(argument);
               y != nullptr) {
        actual = object->less(*y);
    } else {
        BOOST_ERROR("The argument is invalid!");
    }

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] to_string メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.to_string(), expectation.to_string());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスX、またはモッククラスYのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::ComparisonOperable               テスト対象クラス
 * @see sqlxx::expression::ComparisonOperable::less_equal() テスト対象メンバ関数
 * @see ComparisonOperableDataSet::for_some_test_case()     データセット
 * @see ComparisonOperableMockX                             テスト対象クラスを継承したモッククラス（その一）
 * @see ComparisonOperableMockY                             テスト対象クラスを継承したモッククラス（その二）
 */
BOOST_DATA_TEST_CASE(
    less_equal,
    boost::unit_test::data::make(
        ComparisonOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ComparisonOperable const * object = data_set_element.object;

    // テスト対象メンバ関数の引数
    ComparisonOperable const * argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    ConditionExpression const expectation =
        data_set_element.expectation_of_less_equal;

    // テスト対象メンバ関数の引数となるオブジェクトの型を X または Y に変換し、
    // テスト対象メンバ関数を実行する
    ConditionExpression actual;
    if (ComparisonOperableMockX const * x =
            dynamic_cast<ComparisonOperableMockX const *>(argument);
        x != nullptr) {
        actual = object->less_equal(*x);
    } else if (ComparisonOperableMockY const * y =
                   dynamic_cast<ComparisonOperableMockY const *>(argument);
               y != nullptr) {
        actual = object->less_equal(*y);
    } else {
        BOOST_ERROR("The argument is invalid!");
    }

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] to_string メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.to_string(), expectation.to_string());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスX、またはモッククラスYのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::ComparisonOperable            テスト対象クラス
 * @see sqlxx::expression::ComparisonOperable::greater() テスト対象メンバ関数
 * @see ComparisonOperableDataSet::for_some_test_case()  データセット
 * @see ComparisonOperableMockX                          テスト対象クラスを継承したモッククラス（その一）
 * @see ComparisonOperableMockY                          テスト対象クラスを継承したモッククラス（その二）
 */
BOOST_DATA_TEST_CASE(
    greater,
    boost::unit_test::data::make(
        ComparisonOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ComparisonOperable const * object = data_set_element.object;

    // テスト対象メンバ関数の引数
    ComparisonOperable const * argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    ConditionExpression const expectation =
        data_set_element.expectation_of_greater;

    // テスト対象メンバ関数の引数となるオブジェクトの型を X または Y に変換し、
    // テスト対象メンバ関数を実行する
    ConditionExpression actual;
    if (ComparisonOperableMockX const * x =
            dynamic_cast<ComparisonOperableMockX const *>(argument);
        x != nullptr) {
        actual = object->greater(*x);
    } else if (ComparisonOperableMockY const * y =
                   dynamic_cast<ComparisonOperableMockY const *>(argument);
               y != nullptr) {
        actual = object->greater(*y);
    } else {
        BOOST_ERROR("The argument is invalid!");
    }

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] to_string メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.to_string(), expectation.to_string());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスX、またはモッククラスYのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::ComparisonOperable                  テスト対象クラス
 * @see sqlxx::expression::ComparisonOperable::greater_equal() テスト対象メンバ関数
 * @see ComparisonOperableDataSet::for_some_test_case()        データセット
 * @see ComparisonOperableMockX                                テスト対象クラスを継承したモッククラス（その一）
 * @see ComparisonOperableMockY                                テスト対象クラスを継承したモッククラス（その二）
 */
BOOST_DATA_TEST_CASE(
    greater_equal,
    boost::unit_test::data::make(
        ComparisonOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ComparisonOperable const * object = data_set_element.object;

    // テスト対象メンバ関数の引数
    ComparisonOperable const * argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    ConditionExpression const expectation =
        data_set_element.expectation_of_greater_equal;

    // テスト対象メンバ関数の引数となるオブジェクトの型を X または Y に変換し、
    // テスト対象メンバ関数を実行する
    ConditionExpression actual;
    if (ComparisonOperableMockX const * x =
            dynamic_cast<ComparisonOperableMockX const *>(argument);
        x != nullptr) {
        actual = object->greater_equal(*x);
    } else if (ComparisonOperableMockY const * y =
                   dynamic_cast<ComparisonOperableMockY const *>(argument);
               y != nullptr) {
        actual = object->greater_equal(*y);
    } else {
        BOOST_ERROR("The argument is invalid!");
    }

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] to_string メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.to_string(), expectation.to_string());
}

/*!
 * @brief テストパターン :
 *        テスト対象オブジェクトとテスト対象メンバ関数の引数にモッククラスX、またはモッククラスYのオブジェクトを指定し、
 *        テスト対象メンバ関数を呼び出す。
 *
 * @see sqlxx::expression::ComparisonOperable           テスト対象クラス
 * @see sqlxx::expression::ComparisonOperable::is()     テスト対象メンバ関数
 * @see ComparisonOperableDataSet::for_some_test_case() データセット
 * @see ComparisonOperableMockX                         テスト対象クラスを継承したモッククラス（その一）
 * @see ComparisonOperableMockY                         テスト対象クラスを継承したモッククラス（その二）
 */
BOOST_DATA_TEST_CASE(
    is,
    boost::unit_test::data::make(
        ComparisonOperableDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    ComparisonOperable const * object = data_set_element.object;

    // テスト対象メンバ関数の引数
    ComparisonOperable const * argument = data_set_element.argument;

    // テスト対象メンバ関数の期待結果
    ConditionExpression const expectation = data_set_element.expectation_of_is;

    // テスト対象メンバ関数の引数となるオブジェクトの型を X または Y に変換し、
    // テスト対象メンバ関数を実行する
    ConditionExpression actual;
    if (ComparisonOperableMockX const * x =
            dynamic_cast<ComparisonOperableMockX const *>(argument);
        x != nullptr) {
        actual = object->is(*x);
    } else if (ComparisonOperableMockY const * y =
                   dynamic_cast<ComparisonOperableMockY const *>(argument);
               y != nullptr) {
        actual = object->is(*y);
    } else {
        BOOST_ERROR("The argument is invalid!");
    }

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    // TODO [要修正] to_string メンバ関数の戻り値ではなく、メンバ同士を比較して検証すること。
    BOOST_CHECK_EQUAL(actual.to_string(), expectation.to_string());
}

BOOST_AUTO_TEST_SUITE_END(/* class__ComparisonOperable */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__COMPARISON_OPERABLE_CLASS_TEST_CASE_HXX */
