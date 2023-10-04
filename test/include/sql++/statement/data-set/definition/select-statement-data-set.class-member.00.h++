/*!
 * @file select-statement-data-set.class-member.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_00_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_00_HXX

#include <vector>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column-identifier.class.h++>
#include <sql++/identifier/table-identifier.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "../select-statement-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace
{
    using sqlxx::ColumnIdentifier;
    using sqlxx::FromClosure;
    using sqlxx::SelectClosure;
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
            ////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 指定
            //         + as_closure : 指定
            ////////////////////////////////
            // _0
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
            },
            // _1
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people"
            },
            // _2
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _3
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 指定
            //         + as_closure : 未指定
            ////////////////////////////////
            // _4
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name FROM people AS p"
            },
            // _5
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name FROM people"
            },
            // _6
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _7
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 未指定
            //         + as_closure : 指定
            ////////////////////////////////
            // _8
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people AS p"
            },
            // _9
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people"
            },
            // _10
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _11
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}.as({ "p.name" })
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 未指定
            //         + as_closure : 未指定
            ////////////////////////////////
            // _12
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier { "people" }.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people AS p"
            },
            // _13
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier { "people" }
                    }
                },
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id FROM people"
            },
            // _14
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 指定
                    FromClosure {
                        TableIdentifier {}.as({ "p" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _15
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier {}
                    }},
                    // [条件(2)]
                    // + from_closure :
                    //     + table :
                    //         + name       : 未指定
                    //         + as_closure : 未指定
                    FromClosure {
                        TableIdentifier {}
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_00_HXX */
