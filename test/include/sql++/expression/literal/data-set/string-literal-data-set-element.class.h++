/*!
 * @file string-literal-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__STRING_LITERAL_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__STRING_LITERAL_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/literal/string-literal.class.h++>

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
     * @brief ≪文字列リテラル式≫のテストケースで使用するデータセット要素
     *
     * テスト対象オブジェクト及びテスト対象メンバ関数の期待結果を保持する。 @n
     *
     * @see sqlxx::expression::StringLiteral              テスト対象クラス
     * @see sqlxx::test::expression::StringLiteralDataSet データセット
     */
    struct StringLiteralDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        StringLiteral string_literal;

        /*!
         * @brief 期待結果 - @c inner_value メンバ関数
         *
         * @see sqlxx::expression::StringLiteral::inner_value() テスト対象メンバ関数
         */
        std::string expectation_of_inner_value;

        /*!
         * @brief 期待結果 - @c to_string メンバ関数
         *
         * @see sqlxx::expression::StringLiteral::to_string() テスト対象メンバ関数
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
        StringLiteralDataSetElement const & data_set_element) -> std::ostream &;

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
        StringLiteralDataSetElement const & data_set_element) -> std::ostream &
    {
        // clang-format off
        return out << "{ string_literal : \""
                   << data_set_element.string_literal
                   << "\", expectation_of_inner_value : \""
                   << data_set_element.expectation_of_inner_value
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__STRING_LITERAL_DATA_SET_ELEMENT_CLASS_HXX */
