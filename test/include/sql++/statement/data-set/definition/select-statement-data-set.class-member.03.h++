/*!
 * @file select-statement-data-set.class-member.03.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_03_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_03_HXX

#include <vector>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>
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
     * @li @c name       : 未指定
     * @li @c as_closure : 未指定
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
    auto SelectStatementDataSet::for_some_test_case_03()
        -> std::vector<SelectStatementDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + select_closure :
        //     + columns[0] :
        //         + name       : 未指定
        //         + as_closure : 未指定
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
            // _48
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                "SELECT name AS p.name FROM people AS p"
            },
            // _49
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                "SELECT name AS p.name FROM people"
            },
            // _50
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
            // _51
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 指定
            //         + as_closure : 未指定
            ////////////////////////////////////////////////////////////////////
            // _52
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                "SELECT name FROM people AS p"
            },
            // _53
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                "SELECT name FROM people"
            },
            // _54
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
            // _55
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 未指定
            //         + as_closure : 指定
            ////////////////////////////////////////////////////////////////////
            // _56
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                ""
            },
            // _57
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                ""
            },
            // _58
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
            // _59
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + select_closure :
            //     + columns[1] :
            //         + name       : 未指定
            //         + as_closure : 未指定
            ////////////////////////////////////////////////////////////////////
            // _60
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                ""
            },
            // _61
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
                ""
            },
            // _62
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
            // _63
            {
                SelectStatement {
                    SelectClosure {{
                        ColumnIdentifier {},
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
} // namespace statement
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_03_HXX */
