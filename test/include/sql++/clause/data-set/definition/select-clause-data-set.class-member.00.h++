/*!
 * @file select-clause-data-set.class-member.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_00_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_00_HXX

#include <vector>

#include <sql++/clause/select-clause.class.h++>
#include <sql++/identifier/column-identifier.class.h++>

#include "../select-clause-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    using sqlxx::ColumnIdentifier;
    using sqlxx::SelectClause;

    /*!
     * @brief データセットを返却する
     *
     * データパターン : @n
     * @li @c columns : 未指定
     *
     * @return データセット
     *
     * @see sqlxx::clause::SelectClause              テスト対象クラス
     * @see sqlxx::clause::SelectClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::SelectClause::to_string() テスト対象メンバ関数
     */
    auto SelectClauseDataSet::for_some_test_case_00_a()
        -> std::vector<SelectClauseDataSetElement>
    {
        // clang-format off
        return {
            // _0
            {
                // [条件]
                // + columns : 未指定
                SelectClause {},
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }

    /*!
     * @brief データセットを返却する
     *
     * データパターン : @n
     * @li @c columns[1] : 未指定
     *
     * @return データセット
     *
     * @see sqlxx::clause::SelectClause              テスト対象クラス
     * @see sqlxx::clause::SelectClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::SelectClause::to_string() テスト対象メンバ関数
     */
    auto SelectClauseDataSet::for_some_test_case_00_b()
        -> std::vector<SelectClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[1] : 未指定
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 未指定
            ////////////////////////////////////////////////////////////////////
            // _1
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 未指定
                    ColumnIdentifier {}
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _2
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier {}.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _3
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier {}.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _4
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 適格
                    ColumnIdentifier {}.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 空文字列
            ////////////////////////////////////////////////////////////////////
            // _5
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { "" }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _6
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { "" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _7
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { "" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _8
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 適格
                    ColumnIdentifier { "" }.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////////////////////////////////////////
            // _9
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { " " }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _10
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { " " }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _11
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { " " }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _12
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 適格
                    ColumnIdentifier { " " }.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 適格
            ////////////////////////////////////////////////////////////////////
            // _13
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { "id" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _14
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { "id" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _15
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { "id" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _16
            {
                SelectClause {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_clause : 適格
                    ColumnIdentifier { "id" }.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            }
        };
        // clang-format on
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_00_HXX */
