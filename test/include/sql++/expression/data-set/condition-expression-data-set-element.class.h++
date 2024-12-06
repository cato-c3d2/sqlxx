/*!
 * @file condition-expression-data-set-element.class.h++
 */

// FIXME 【要修正】ファイル名を変更する予定 : condition-expression*.h++ => binary-operation*.h++

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <optional>
#include <string>

#include <sql++/expression/operation/binary-operation.class.h++>

namespace sqlxx::test
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪二項演算式≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する。
     *
     * @see sqlxx::expression::BinaryOperation              テスト対象クラス
     * @see sqlxx::test::expression::BinaryOperationDataSet データセット
     */
    struct BinaryOperationDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト - 非DSL記法
         */
        BinaryOperation binary_operation;

        /*!
         * @brief テスト対象オブジェクト - DSL記法
         */
        std::optional<BinaryOperation> binary_operation_as_dsl;

        /*!
         * @brief 期待結果 - @c empty メンバ関数
         *
         * @see sqlxx::expression::BinaryOperation::empty() テスト対象メンバ関数
         */
        bool expectation_of_empty;

        /*!
         * @brief 期待結果 - @c to_string メンバ関数
         *
         * @see sqlxx::expression::BinaryOperation::to_string() テスト対象メンバ関数
         */
        std::string expectation_of_to_string;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算(本データセット要素)
     *
     * @param[in] out              出力ストリーム
     * @param[in] data_set_element データセット要素
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream &                        out,
        BinaryOperationDataSetElement const & data_set_element)
        -> std::ostream &;

    /*!
     * @brief ストリーム出力演算(テスト対象オブジェクト(任意指定))
     *
     * @param[in] out                       出力ストリーム
     * @param[in] optional_binary_operation テスト対象オブジェクト(任意指定)
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream &                         out,
        std::optional<BinaryOperation> const & optional_binary_operation)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // No class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(
        std::ostream &                        out,
        BinaryOperationDataSetElement const & data_set_element)
        -> std::ostream &
    {
        // clang-format off
        return out << "{ binary_operation : \""
                   << data_set_element.binary_operation
                   << "\", binary_operation_as_dsl : \""
                   << data_set_element.binary_operation_as_dsl
                   << "\", expectation_of_empty : \""
                   << data_set_element.expectation_of_empty
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string
                   << "\" }";
        // clang-format on
    }

    auto operator<<(
        std::ostream &                         out,
        std::optional<BinaryOperation> const & optional_binary_operation)
        -> std::ostream &
    {
        if (! optional_binary_operation) {
            return out << "( null-optional )";
        }
        return out << optional_binary_operation.value();
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX */
