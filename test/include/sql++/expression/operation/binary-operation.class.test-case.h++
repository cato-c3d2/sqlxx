/*!
 * @file binary-operation.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/integer-literal.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>

#include "./data-set/binary-operation-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__expression)

BOOST_AUTO_TEST_SUITE(class__BinaryOperation)

using sqlxx::BinaryOperation;
using sqlxx::BinaryOperationKind;
using sqlxx::Expression;
using sqlxx::IdentifierExpression;
using sqlxx::IntegerLiteral;
using sqlxx::test::BinaryOperationDataSet;

/*!
 * @brief テストパターン :
 *        @c BinaryOperation オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::expression::BinaryOperation テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    BinaryOperation const source      = {}; // コピー元のオブジェクト
    BinaryOperation       destination = {   // コピー先のオブジェクト
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
 *        @c const な @c BinaryOperation オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::BinaryOperation          テスト対象クラス
 * @see sqlxx::expression::BinaryOperation::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_constant)
{
    // 複製元のオブジェクト
    Expression const * source =
        new BinaryOperation { IdentifierExpression { "p.id" }.equal_to(1234) };

    // 複製元のオブジェクトを複製し、複製先のオブジェクトへ代入する
    Expression const * destination = source->clone();

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source->evaluate() == destination->evaluate());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        非 @c const な @c BinaryOperation オブジェクトが複製可能であることを検証する
 *
 * @see sqlxx::expression::BinaryOperation          テスト対象クラス
 * @see sqlxx::expression::BinaryOperation::clone() テスト対象メンバ関数
 */
BOOST_AUTO_TEST_CASE(clone_of_non_constant)
{
    // 複製元のオブジェクト
    Expression * source =
        new BinaryOperation { IdentifierExpression { "p.id" }.equal_to(1234) };

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
 *        @c BinaryOperation オブジェクトに対して各種アクセサを呼び出す
 *
 * @see sqlxx::expression::BinaryOperation                     テスト対象クラス
 * @see sqlxx::expression::BinaryOperation::operater()         テスト対象メンバ関数（ getter 及び setter ）
 * @see sqlxx::expression::BinaryOperation::left_expression()  テスト対象メンバ関数（ getter 及び setter ）
 * @see sqlxx::expression::BinaryOperation::right_expression() テスト対象メンバ関数（ getter 及び setter ）
 */
BOOST_AUTO_TEST_CASE(accessers)
{
    // テスト対象オブジェクト
    BinaryOperation binary_operation {};

    // テスト対象オブジェクトに設定する≪二項演算種別≫
    BinaryOperationKind const operater_to_set = BinaryOperationKind::EqualTo;

    // テスト対象オブジェクトに設定する左辺の≪式≫
    IdentifierExpression const left_expression_to_set = { "p.id" };

    // テスト対象オブジェクトに設定する右辺の≪式≫
    IntegerLiteral const right_expression_to_set = { 1234 };

    ////////////////////////////////////////////////////////////////////////////
    // 初期値の検証
    ////////////////////////////////////////////////////////////////////////////

    // ≪二項演算種別≫は≪未定≫であること
    BOOST_CHECK(binary_operation.operater() == BinaryOperationKind::None);

    // 左辺の≪式≫はヌルポインタであること
    BOOST_CHECK(binary_operation.left_expression() == nullptr);

    // 右辺の≪式≫はヌルポインタであること
    BOOST_CHECK(binary_operation.right_expression() == nullptr);

    ////////////////////////////////////////////////////////////////////////////
    // テスト対象メンバ関数（ setter ）の検証
    ////////////////////////////////////////////////////////////////////////////

    // テスト対象オブジェクトに≪二項演算種別≫、左辺の≪式≫及び右辺の≪式≫を設定する
    BinaryOperation & binary_operation_reference =
        binary_operation.operater(operater_to_set)
            .left_expression(left_expression_to_set)
            .right_expression(right_expression_to_set);

    // 【戻り値の検証】
    // テスト対象オブジェクトを指す参照であること（アドレスが一致すること）
    BOOST_CHECK(
        std::addressof(binary_operation)
        == std::addressof(binary_operation_reference));

    ////////////////////////////////////////////////////////////////////////////
    // テスト対象メンバ関数（ getter ）の検証
    ////////////////////////////////////////////////////////////////////////////

    // テスト対象オブジェクトが保持する≪二項演算種別≫、左辺の≪式≫及び右辺の≪式≫を取得する
    BinaryOperationKind const operater_to_get = binary_operation.operater();
    Expression const * const  left_expression_to_get =
        binary_operation.left_expression();
    Expression const * const right_expression_to_get =
        binary_operation.right_expression();

    // 【戻り値の検証】
    // 設定した各種オブジェクトとは等価ではあるが等値ではないこと（アドレスが一致しないこと）
    BOOST_CHECK(operater_to_get == operater_to_set);
    BOOST_CHECK(
        std::addressof(operater_to_get) != std::addressof(operater_to_set));
    BOOST_CHECK(
        left_expression_to_get->evaluate()
        == left_expression_to_set.evaluate());
    BOOST_CHECK(
        std::addressof(*left_expression_to_get)
        != std::addressof(left_expression_to_set));
    BOOST_CHECK(
        right_expression_to_get->evaluate()
        == right_expression_to_set.evaluate());
    BOOST_CHECK(
        std::addressof(*right_expression_to_get)
        != std::addressof(right_expression_to_set));

    ////////////////////////////////////////////////////////////////////////////
    // テスト対象メンバ関数（ getter ）の検証
    ////////////////////////////////////////////////////////////////////////////

    // テスト対象オブジェクトを SQL として評価し、その結果が期待結果と一致すること
    BOOST_CHECK_EQUAL(binary_operation.evaluate(), "p.id = 1234");
}

/*!
 * @brief テストパターン :
 *        非 DSL 記法で構築した @c BinaryOperation オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::expression::BinaryOperation           テスト対象クラス
 * @see sqlxx::expression::BinaryOperation::empty()  テスト対象メンバ関数
 * @see BinaryOperationDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty_as_non_dsl,
    boost::unit_test::data::make(BinaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト - 非DSL記法
    BinaryOperation const binary_operation = data_set_element.binary_operation;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = binary_operation.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        DSL 記法で構築した @c BinaryOperation オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::expression::BinaryOperation           テスト対象クラス
 * @see sqlxx::expression::BinaryOperation::empty()  テスト対象メンバ関数
 * @see BinaryOperationDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty_as_dsl,
    boost::unit_test::data::make(BinaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    if (! data_set_element.binary_operation_as_dsl) {
        // DSL 記法のテスト対象オブジェクトが設定されていない場合
        // 本テストケースは実施しない
        return;
    }

    // テスト対象オブジェクト - DSL記法
    BinaryOperation const binary_operation =
        data_set_element.binary_operation_as_dsl.value();

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = binary_operation.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        非 DSL 記法で構築した @c BinaryOperation オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::BinaryOperation              テスト対象クラス
 * @see sqlxx::expression::BinaryOperation::to_string() テスト対象メンバ関数
 * @see BinaryOperationDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string_as_non_dsl,
    boost::unit_test::data::make(BinaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト - 非DSL記法
    BinaryOperation const binary_operation = data_set_element.binary_operation;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = binary_operation.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        DSL 記法で構築した @c BinaryOperation オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::expression::BinaryOperation              テスト対象クラス
 * @see sqlxx::expression::BinaryOperation::to_string() テスト対象メンバ関数
 * @see BinaryOperationDataSet::for_some_test_case()    データセット
 */
BOOST_DATA_TEST_CASE(
    to_string_as_dsl,
    boost::unit_test::data::make(BinaryOperationDataSet::for_some_test_case()),
    data_set_element)
{
    if (! data_set_element.binary_operation_as_dsl) {
        // DSL 記法のテスト対象オブジェクトが設定されていない場合
        // 本テストケースは実施しない
        return;
    }

    // テスト対象オブジェクト - DSL記法
    BinaryOperation const binary_operation =
        data_set_element.binary_operation_as_dsl.value();

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = binary_operation.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__BinaryOperation */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__expression */)

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_TEST_CASE_HXX */
