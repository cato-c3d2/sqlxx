/*!
 * @file identifier-expression-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__IDENTIFIER_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__IDENTIFIER_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/identifier-expression.class.h++>

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
     * @brief ≪リテラル式≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する。 @n
     *
     * @see sqlxx::expression::IdentifierExpression              テスト対象クラス
     * @see sqlxx::test::expression::IdentifierExpressionDataSet データセット
     */
    struct IdentifierExpressionDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        IdentifierExpression identifier_expression;

        /*!
         * @brief 期待結果 - @c name メンバ関数 & @c to_string メンバ関数
         *
         * @see sqlxx::expression::IdentifierExpression::name()      テスト対象メンバ関数
         * @see sqlxx::expression::IdentifierExpression::to_string() テスト対象メンバ関数
         */
        std::string expectation_of_name_and_to_string;
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
        std::ostream &                             out,
        IdentifierExpressionDataSetElement const & data_set_element)
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
        std::ostream &                             out,
        IdentifierExpressionDataSetElement const & data_set_element)
        -> std::ostream &
    {
        // clang-format off
        return out << "{ identifier_expression : \""
                   << data_set_element.identifier_expression
                   << "\", expectation_of_name_and_to_string : \""
                   << data_set_element.expectation_of_name_and_to_string
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__IDENTIFIER_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX */
