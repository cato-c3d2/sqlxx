/*!
 * @file where-clause-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <optional>
#include <string>

#include <sql++/clause/where-clause.class.h++>

namespace sqlxx::test
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪WHERE句≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する。
     *
     * @see sqlxx::clause::WhereClause              テスト対象クラス
     * @see sqlxx::test::clause::WhereClauseDataSet データセット
     */
    struct WhereClauseDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト - 非DSL記法
         */
        WhereClause where_clause;

        /*!
         * @brief テスト対象オブジェクト - DSL記法
         */
        std::optional<WhereClause> where_clause_as_dsl;

        /*!
         * @brief 期待結果 - @c empty メンバ関数
         *
         * @see sqlxx::clause::WhereClause::empty() テスト対象メンバ関数
         */
        bool expectation_of_empty;

        /*!
         * @brief 期待結果 - @c to_string メンバ関数
         *
         * @see sqlxx::clause::WhereClause::to_string() テスト対象メンバ関数
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
        std::ostream & out, WhereClauseDataSetElement const & data_set_element)
        -> std::ostream &;

    /*!
     * @brief ストリーム出力演算(テスト対象オブジェクト(任意指定))
     *
     * @param[in] out                   出力ストリーム
     * @param[in] optional_where_clause テスト対象オブジェクト(任意指定)
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream &                     out,
        std::optional<WhereClause> const & optional_where_clause)
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
        std::ostream & out, WhereClauseDataSetElement const & data_set_element)
        -> std::ostream &
    {
        // clang-format off
        return out << "{ where_clause : \""
                   << data_set_element.where_clause
                   << "\", where_clause_as_dsl : \""
                   << data_set_element.where_clause_as_dsl
                   << "\", expectation_of_empty : \""
                   << data_set_element.expectation_of_empty
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string
                   << "\" }";
        // clang-format on
    }

    auto operator<<(
        std::ostream &                     out,
        std::optional<WhereClause> const & optional_where_clause)
        -> std::ostream &
    {
        if (! optional_where_clause) {
            return out << "( null-optional )";
        }
        return out << optional_where_clause.value();
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_ELEMENT_CLASS_HXX */
