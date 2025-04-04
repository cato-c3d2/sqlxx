/*!
 * @file grouped-expression-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__GROUPED_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__GROUPED_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/grouped-expression.class.h++>

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
     * @brief ≪グループ化された式≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する。 @n
     *
     * @see sqlxx::expression::GroupedExpression              テスト対象クラス
     * @see sqlxx::test::expression::GroupedExpressionDataSet データセット
     */
    struct GroupedExpressionDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        GroupedExpression grouped_expression;

        /*!
         * @brief 期待結果 - @c empty メンバ関数
         *
         * @see sqlxx::expression::GroupedExpression::empty() テスト対象メンバ関数
         */
        bool expectation_of_empty;

        /*!
         * @brief 期待結果 - @c to_string メンバ関数
         *
         * @see sqlxx::expression::GroupedExpression::to_string() テスト対象メンバ関数
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
        std::ostream &                          out,
        GroupedExpressionDataSetElement const & data_set_element)
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
        std::ostream &                          out,
        GroupedExpressionDataSetElement const & data_set_element)
        -> std::ostream &
    {
        // clang-format off
        return out << "{ grouped_expression : \""
                   << data_set_element.grouped_expression
                   << "\", expectation_of_empty : \""
                   << data_set_element.expectation_of_empty
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__GROUPED_EXPRESSION_DATA_SET_ELEMENT_CLASS_HXX */
