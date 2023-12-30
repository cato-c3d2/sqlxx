/*!
 * @file select-statement-data-set.class-member.02.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_02_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_02_HXX

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
     * @c select_clause :
     *
     * @c columns[0] : @n
     * @li @c name      : 未指定
     * @li @c as_clause : 指定
     *
     * @c columns[1] : @n
     * @li @c name      : 指定 or 未指定
     * @li @c as_clause : 指定 or 未指定
     *
     * @c from_clause :
     *
     * @c table : @n
     * @li @c name      : 指定 or 未指定
     * @li @c as_clause : 指定 or 未指定
     *
     * @return データセット
     *
     * @see sqlxx::statement::SelectStatement              テスト対象クラス
     * @see sqlxx::statement::SelectStatement::to_string() テスト対象メンバ関数
     */
    auto SelectStatementDataSet::for_some_test_case_02()
        -> std::vector<SelectStatementDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + select_clause :
        //     + columns[0] :
        //         + name      : 未指定
        //         + as_clause : 指定
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_clause :
            //     + columns[1] :
            //         + name      : 指定
            //         + as_clause : 指定
            ////////////////////////////////////////////////////////////////////
            // _32
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT name AS p.name FROM people AS p"
            },
            // _33
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 未指定
                    FromClause {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT name AS p.name FROM people"
            },
            // _34
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _35
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 未指定
                    FromClause {
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_clause :
            //     + columns[1] :
            //         + name      : 指定
            //         + as_clause : 未指定
            ////////////////////////////////////////////////////////////////////
            // _36
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT name FROM people AS p"
            },
            // _37
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 未指定
                    FromClause {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT name FROM people"
            },
            // _38
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _39
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 未指定
                    FromClause {
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_clause :
            //     + columns[1] :
            //         + name      : 未指定
            //         + as_clause : 指定
            ////////////////////////////////////////////////////////////////////
            // _40
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _41
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 未指定
                    FromClause {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _42
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _43
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 未指定
                    FromClause {
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_clause :
            //     + columns[1] :
            //         + name      : 未指定
            //         + as_clause : 未指定
            ////////////////////////////////////////////////////////////////////
            // _44
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _45
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 指定
                    //         + as_clause : 未指定
                    FromClause {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _46
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 指定
                    FromClause {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _47
            {
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier {}.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_clause :
                    //     + table :
                    //         + name      : 未指定
                    //         + as_clause : 未指定
                    FromClause {
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

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_02_HXX */
