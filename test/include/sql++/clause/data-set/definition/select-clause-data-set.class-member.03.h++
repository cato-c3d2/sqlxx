/*!
 * @file select-clause-data-set.class-member.03.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_03_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_03_HXX

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
     * @li @c as_clause : 不適格(半角スペース)
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
    auto SelectClauseDataSet::for_some_test_case_03()
        -> std::vector<SelectClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[0] :
        //     + name      : 未指定
        //     + as_clause : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 未指定
            ////////////////////////////////////////////////////////////////////
            // _49
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _50
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _51
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _52
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _53
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _54
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _55
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _56
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _57
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _58
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _59
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _60
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _61
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _62
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _63
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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
            // _64
            {
                SelectClause {
                    ColumnIdentifier {}.as({ " " }),
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

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_03_HXX */
