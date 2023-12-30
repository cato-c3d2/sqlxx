/*!
 * @file select-clause-data-set.class-member.04.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_04_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_04_HXX

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
     * データパターン :
     *
     * @c columns[0] : @n
     * @li @c name      : 未指定
     * @li @c as_clause : 適格
     *
     * @c columns[1] : @n
     * @li @c name      : 未指定, 空文字列, 不適格(半角スペース) or 適格
     * @li @c as_clause : 未指定, 空文字列, 不適格(半角スペース) or 適格
     *
     * @return データセット
     *
     * @see sqlxx::clause::SelectClause              テスト対象クラス
     * @see sqlxx::clause::SelectClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::SelectClause::to_string() テスト対象メンバ関数
     */
    auto SelectClauseDataSet::for_some_test_case_04()
        -> std::vector<SelectClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[0] :
        //     + name      : 未指定
        //     + as_clause : 適格
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 未指定
            ////////////////////////////////////////////////////////////////////
            // _65
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier {}
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _66
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier {}.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _67
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier {}.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _68
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier {}.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 空文字列
            ////////////////////////////////////////////////////////////////////
            // _69
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { "" }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _70
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { "" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _71
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { "" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _72
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier { "" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////////////////////////////////////////
            // _73
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { " " }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _74
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { " " }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _75
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { " " }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _76
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier { " " }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 適格
            ////////////////////////////////////////////////////////////////////
            // _77
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { "name" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name"
            },
            // _78
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { "name" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name"
            },
            // _79
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { "name" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name"
            },
            // _80
            {
                SelectClause {
                    ColumnIdentifier {}.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier { "name" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name AS p.name"
            }
        };
        // clang-format on
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_04_HXX */
