/*!
 * @file null-literal-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__NULL_LITERAL_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__NULL_LITERAL_DATA_SET_ELEMENT_CLASS_HXX

#include <cstddef> // for std::nullptr_t
#include <iostream>
#include <string>

#include <sql++/expression/literal/null-literal.class.h++>

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
     * @brief ≪NULLリテラル式≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する。 @n
     *
     * @see sqlxx::expression::NullLiteral              テスト対象クラス
     * @see sqlxx::test::expression::NullLiteralDataSet データセット
     */
    struct NullLiteralDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        NullLiteral null_literal;

        /*!
         * @brief 期待結果 - @c inner_value メンバ関数
         *
         * @see sqlxx::expression::NullLiteral::inner_value() テスト対象メンバ関数
         */
        std::nullptr_t expectation_of_inner_value;

        /*!
         * @brief 期待結果 - @c to_string メンバ関数
         *
         * @see sqlxx::expression::NullLiteral::to_string() テスト対象メンバ関数
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
        std::ostream & out, NullLiteralDataSetElement const & data_set_element)
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
        std::ostream & out, NullLiteralDataSetElement const & data_set_element)
        -> std::ostream &
    {
        // clang-format off
        return out << "{ null_literal : \""
                   << data_set_element.null_literal
                   << "\", expectation_of_inner_value : \""
                   << data_set_element.expectation_of_inner_value
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__NULL_LITERAL_DATA_SET_ELEMENT_CLASS_HXX */
