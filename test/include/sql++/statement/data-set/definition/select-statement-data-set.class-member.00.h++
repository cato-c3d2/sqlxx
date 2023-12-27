/*!
 * @file select-statement-data-set.class-member.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_00_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_00_HXX

#include <vector>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>
#include <sql++/identifier/column-identifier.class.h++>
#include <sql++/identifier/table-identifier.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "../select-statement-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace statement
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    using sqlxx::ColumnIdentifier;
    using sqlxx::FromClause;
    using sqlxx::SelectClause;
    using sqlxx::SelectStatement;
    using sqlxx::TableIdentifier;

    /*!
     * @brief  データセットを返却する
     *
     * データパターン :
     *
     * @c select_closure :
     *
     * @c columns[0] : @n
     * @li @c name       : 指定
     * @li @c as_closure : 指定
     *
     * @c columns[1] : @n
     * @li @c name       : 指定 or 未指定
     * @li @c as_closure : 指定 or 未指定
     *
     * @c from_closure :
     *
     * @c table : @n
     * @li @c name       : 指定 or 未指定
     * @li @c as_closure : 指定 or 未指定
     *
     * @return データセット
     *
     * @see sqlxx::statement::SelectStatement              テスト対象クラス
     * @see sqlxx::statement::SelectStatement::to_string() テスト対象メンバ関数
     */
    auto SelectStatementDataSet::for_some_test_case_00()
        -> std::vector<SelectStatementDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + select_closure :
        //     + columns[0] :
        //         + name       : 指定
        //         + as_closure : 指定
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 指定
            //         + as_closure : 指定
            ////////////////////////////////////////////////////////////////////
            // _0
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
            },
            // _1
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people"
            },
            // _2
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _3
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 指定
            //         + as_closure : 未指定
            ////////////////////////////////////////////////////////////////////
            // _4
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name FROM people AS p"
            },
            // _5
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name FROM people"
            },
            // _6
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _7
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 未指定
            //         + as_closure : 指定
            ////////////////////////////////////////////////////////////////////
            // _8
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people AS p"
            },
            // _9
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people"
            },
            // _10
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _11
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 未指定
            //         + as_closure : 未指定
            ////////////////////////////////////////////////////////////////////
            // _12
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people AS p"
            },
            // _13
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people"
            },
            // _14
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClause{
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _15
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClause{
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }
} // namespace statement
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_00_HXX */
