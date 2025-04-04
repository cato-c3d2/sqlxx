/*!
 * @file integer-literal-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__INTEGER_LITERAL_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__INTEGER_LITERAL_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/literal/integer-literal.class.h++>

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
     * @brief ≪整数リテラル式≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する。 @n
     *
     * @see sqlxx::expression::IntegerLiteral              テスト対象クラス
     * @see sqlxx::test::expression::IntegerLiteralDataSet データセット
     */
    struct IntegerLiteralDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        IntegerLiteral integer_literal;

        /*!
         * @brief 期待結果 - @c inner_value メンバ関数
         *
         * @see sqlxx::expression::BooleanLiteral::inner_value() テスト対象メンバ関数
         */
        int expectation_of_inner_value;

        /*!
         * @brief 期待結果 - @c to_string メンバ関数
         *
         * @see sqlxx::expression::BooleanLiteral::to_string() テスト対象メンバ関数
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
        std::ostream &                       out,
        IntegerLiteralDataSetElement const & data_set_element)
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
        std::ostream &                       out,
        IntegerLiteralDataSetElement const & data_set_element) -> std::ostream &
    {
        // clang-format off
        return out << "{ integer_literal : \""
                   << data_set_element.integer_literal
                   << "\", expectation_of_inner_value : \""
                   << data_set_element.expectation_of_inner_value
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__INTEGER_LITERAL_DATA_SET_ELEMENT_CLASS_HXX */
