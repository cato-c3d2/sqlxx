/*!
 * @file select-statement-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/statement/select-statement.class.h++>

namespace sqlxx::test
{
inline namespace
{
    using sqlxx::statement::SelectStatement;

    /*!
     * @brief データセットの要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する.
     */
    struct SelectStatementDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        SelectStatement select_statement;

        /*!
         * @brief @c to_string メンバ関数の期待結果
         */
        std::string expectation_of_to_string;
    };

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] data_set_element データセットの要素
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream &                        out,
        SelectStatementDataSetElement const & data_set_element)
        -> std::ostream &
    {
        return out << "{ select_statement : \""
                   << data_set_element.select_statement
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string << "\" }";
    }
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_ELEMENT_CLASS_HXX */
