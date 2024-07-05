/*!
 * @file operation-kind-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION_KIND_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION_KIND_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/operation/operation-kind.enum-class.h++>

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
     * @brief ≪演算種別≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象の関数の期待結果を保持する。
     *
     * @see sqlxx::expression::OperationKind              テスト対象オブジェクトの型
     * @see sqlxx::test::expression::OperationKindDataSet データセット
     */
    struct OperationKindDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        OperationKind operation_kind;

        /*!
         * @brief 期待結果 - @c to_string 関数
         *
         * @see sqlxx::expression::OperationKind::to_string() テスト対象関数
         */
        std::string expectation_of_to_string;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] data_set_element データセット要素
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream &                      out,
        OperationKindDataSetElement const & data_set_element) -> std::ostream &;

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
        std::ostream &                      out,
        OperationKindDataSetElement const & data_set_element) -> std::ostream &
    {
        // clang-format off
        return out << "{ operation_kind : \""
                   // TODO [要修正] enum-class のストリーム出力演算子を定義すること。
                   // << data_set_element.operation_kind
                   << to_string(data_set_element.operation_kind)
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION_KIND_DATA_SET_ELEMENT_CLASS_HXX */
