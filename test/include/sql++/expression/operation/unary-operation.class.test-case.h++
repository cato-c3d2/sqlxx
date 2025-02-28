/*!
 * @file unary-operation.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/literal/null-literal.class.h++>
#include <sql++/expression/operation/unary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/unary-operation.class.h++>

#include "./data-set/unary-operation-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__UnaryOperation)

using sqlxx::Expression;
using sqlxx::NullLiteral;
using sqlxx::UnaryOperation;
using sqlxx::UnaryOperationKind;
using sqlxx::test::UnaryOperationDataSet;

/*!
 * @brief テストパターン :
 *        @c UnaryOperation オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::expression::UnaryOperation テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    UnaryOperation const source      = {}; // コピー元のオブジェクト
    UnaryOperation       destination = {   // コピー先のオブジェクト
        sqlxx::logical_not(sqlxx::null)
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
 *        @c const な @c UnaryOperation オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::UnaryOperation          テスト対象クラス
 * @see sqlxx::expression::UnaryOperation::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_constant)
{
    // 複製元のオブジェクト
    Expression const * source = new UnaryOperation {
        UnaryOperationKind::LogicalNot,
        NullLiteral {},
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
 *        非 @c const な @c UnaryOperation オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::UnaryOperation          テスト対象クラス
 * @see sqlxx::expression::UnaryOperation::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_non_constant)
{
    // 複製元のオブジェクト
    Expression const * source = new UnaryOperation {
        UnaryOperationKind::LogicalNot,
        NullLiteral {},
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
 *        @c UnaryOperation オブジェクトに対して各種アクセサを呼び出す
 *
 * @see sqlxx::expression::UnaryOperation                   テスト対象クラス
 * @see sqlxx::expression::UnaryOperation::operation_kind() テスト対象メンバ関数（ getter 及び setter ）
 * @see sqlxx::expression::UnaryOperation::operand()        テスト対象メンバ関数（ getter 及び setter ）
 */
BOOST_AUTO_TEST_CASE(accessers)
{
    // テスト対象オブジェクト
    UnaryOperation unary_operation {};

    // テスト対象オブジェクトに設定する≪単項演算種別≫
    UnaryOperationKind const operation_kind_to_set =
        UnaryOperationKind::LogicalNot;

    // テスト対象オブジェクトに設定する演算される≪式≫
    NullLiteral const operand_to_set = {};

    ////////////////////////////////////////////////////////////////////////////
    // 初期値の検証
    ////////////////////////////////////////////////////////////////////////////

    // ≪単項演算種別≫は≪未定≫であること
    BOOST_CHECK(unary_operation.operation_kind() == UnaryOperationKind::None);

    // 演算される≪式≫はヌルポインタであること
    BOOST_CHECK(unary_operation.operand() == nullptr);

    ////////////////////////////////////////////////////////////////////////////
    // テスト対象メンバ関数（ setter ）の検証
    ////////////////////////////////////////////////////////////////////////////

    // テスト対象オブジェクトに≪単項演算種別≫及び演算される≪式≫を設定する
    UnaryOperation & unary_operation_reference =
        unary_operation.operation_kind(operation_kind_to_set)
            .operand(operand_to_set);

    // 【戻り値の検証】
    // テスト対象オブジェクトを指す参照であること（アドレスが一致すること）
    BOOST_CHECK(
        std::addressof(unary_operation)
        == std::addressof(unary_operation_reference));

    ////////////////////////////////////////////////////////////////////////////
    // テスト対象メンバ関数（ getter ）の検証
    ////////////////////////////////////////////////////////////////////////////

    // テスト対象オブジェクトが保持する≪単項演算種別≫及び演算される≪式≫を取得する
    UnaryOperationKind const operation_kind_to_get =
        unary_operation.operation_kind();
    Expression const * const operand_to_get = unary_operation.operand();

    // 【戻り値の検証】
    // 設定した各種オブジェクトとは等価ではあるが等値ではないこと（アドレスが一致しないこと）
    BOOST_CHECK(operation_kind_to_get == operation_kind_to_set);
    BOOST_CHECK(
        std::addressof(operation_kind_to_get)
        != std::addressof(operation_kind_to_set));
    BOOST_CHECK(operand_to_get->evaluate() == operand_to_set.evaluate());
    BOOST_CHECK(
        std::addressof(*operand_to_get) != std::addressof(operand_to_set));

    ////////////////////////////////////////////////////////////////////////////
    // テスト対象メンバ関数（ getter ）の検証
    ////////////////////////////////////////////////////////////////////////////

    // テスト対象オブジェクトを SQL として評価し、その結果が期待結果と一致すること
    BOOST_CHECK_EQUAL(unary_operation.evaluate(), "NOT NULL");
}

/*!
 * @brief テストパターン :
 *        非 DSL 記法で構築した @c UnaryOperation オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::expression::UnaryOperation           テスト対象クラス
 * @see sqlxx::expression::UnaryOperation::empty()  テスト対象メンバ関数
 * @see UnaryOperationDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty_as_non_dsl,
    boost::unit_test::data::make(UnaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト - 非DSL記法
    UnaryOperation const unary_operation = data_set_element.unary_operation;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = unary_operation.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        DSL 記法で構築した @c UnaryOperation オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::expression::UnaryOperation           テスト対象クラス
 * @see sqlxx::expression::UnaryOperation::empty()  テスト対象メンバ関数
 * @see UnaryOperationDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty_as_dsl,
    boost::unit_test::data::make(UnaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    if (! data_set_element.unary_operation_as_dsl) {
        // DSL 記法のテスト対象オブジェクトが設定されていない場合
        // 本テストケースは実施しない
        return;
    }

    // テスト対象オブジェクト - DSL記法
    UnaryOperation const unary_operation =
        data_set_element.unary_operation_as_dsl.value();

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = unary_operation.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        非 DSL 記法で構築した @c UnaryOperation オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::UnaryOperation              テスト対象クラス
 * @see sqlxx::expression::UnaryOperation::to_string() テスト対象メンバ関数
 * @see UnaryOperationDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string_as_non_dsl,
    boost::unit_test::data::make(UnaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト - 非DSL記法
    UnaryOperation const unary_operation = data_set_element.unary_operation;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = unary_operation.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        DSL 記法で構築した @c UnaryOperation オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::UnaryOperation              テスト対象クラス
 * @see sqlxx::expression::UnaryOperation::to_string() テスト対象メンバ関数
 * @see UnaryOperationDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string_as_dsl,
    boost::unit_test::data::make(UnaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    if (! data_set_element.unary_operation_as_dsl) {
        // DSL 記法のテスト対象オブジェクトが設定されていない場合
        // 本テストケースは実施しない
        return;
    }

    // テスト対象オブジェクト - DSL記法
    UnaryOperation const unary_operation =
        data_set_element.unary_operation_as_dsl.value();

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = unary_operation.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__UnaryOperation */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_CLASS_TEST_CASE_HXX */
