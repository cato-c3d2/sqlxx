/*!
 * @file from-clause-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__FROM_CLAUSE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__FROM_CLAUSE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/clause/from-clause.class.h++>

namespace sqlxx::test
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    using sqlxx::FromClause;

    /*!
     * @brief データセットの要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する.
     */
    struct FromClauseDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        FromClause from_clause;

        /*!
         * @brief @c empty メンバ関数の期待結果
         */
        bool expectation_of_empty;

        /*!
         * @brief @c to_string メンバ関数の期待結果
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
     * @param[in] data_set_element データセットの要素
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream & out, FromClauseDataSetElement const & data_set_element)
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
        std::ostream & out, FromClauseDataSetElement const & data_set_element)
        -> std::ostream &
    {
        return out << "{ from_clause : \"" << data_set_element.from_clause
                   << "\", expectation_of_empty : \""
                   << data_set_element.expectation_of_empty
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string << "\" }";
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__FROM_CLAUSE_DATA_SET_ELEMENT_CLASS_HXX */
