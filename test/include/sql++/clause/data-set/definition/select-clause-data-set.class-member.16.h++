/*!
 * @file select-clause-data-set.class-member.16.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_16_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_16_HXX

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
     * @li @c name      : 適格
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
    auto SelectClauseDataSet::for_some_test_case_16()
        -> std::vector<SelectClauseDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[0] :
        //     + name      : 適格
        //     + as_clause : 適格
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 未指定
            ////////////////////////////////////////////////////////////////////
            // _257
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier {}
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _258
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier {}.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _259
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier {}.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _260
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier {}.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 空文字列
            ////////////////////////////////////////////////////////////////////
            // _261
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { "" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _262
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { "" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _263
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { "" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _264
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier { "" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////////////////////////////////////////
            // _265
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { " " }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _266
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { " " }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _267
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { " " }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _268
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier { " " }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 適格
            ////////////////////////////////////////////////////////////////////
            // _269
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 未指定
                    ColumnIdentifier { "name" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name"
            },
            // _270
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 空文字列
                    ColumnIdentifier { "name" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name"
            },
            // _271
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 不適格(半角スペース)
                    ColumnIdentifier { "name" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name"
            },
            // _272
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_clause : 適格
                    ColumnIdentifier { "name" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name AS p.name"
            }
        };
        // clang-format on
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__DEFINITION__SELECT_CLAUSE_DATA_SET_CLASS_MEMBER_16_HXX */
