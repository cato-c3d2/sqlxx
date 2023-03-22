/*!
 * @file select-statement.data-set.03.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_03_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_03_HXX

#include <vector>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column.class.h++>
#include <sql++/identifier/table.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "./select-statement-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__statement)

BOOST_AUTO_TEST_SUITE(class__SelectStatement)

using sqlxx::closure::FromClosure;
using sqlxx::closure::SelectClosure;
using sqlxx::identifier::Column;
using sqlxx::identifier::Table;
using sqlxx::statement::SelectStatement;

/*!
 * @brief  データセットを返却する
 *
 * データパターン :
 *
 * @c select_closure :
 *
 * @c columns[0] : @n
 * @li @c column_name : 未指定
 * @li @c alias_name  : 未指定
 *
 * @c columns[1] : @n
 * @li @c column_name : 指定 or 未指定
 * @li @c alias_name  : 指定 or 未指定
 *
 * @c from_closure :
 *
 * @c table : @n
 * @li @c table_name  : 指定 or 未指定
 * @li @c alias_name  : 指定 or 未指定
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectStatement              テスト対象クラス
 * @see sqlxx::closure::SelectStatement::to_string() テスト対象メンバ関数
 */
auto data_set_03() -> std::vector<SelectStatementDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + select_closure :
    //     + columns[0] :
    //         + column_name : 未指定
    //         + alias_name  : 未指定
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        ////////////////////////////////
        // [条件(1)]
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 指定
        //         + alias_name  : 指定
        ////////////////////////////////
        // _48
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name", "p.name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 指定
                FromClosure {
                    Table { "people", "p" }
                }
            },
            // [期待結果] to_string メンバ関数
            "SELECT name AS p.name FROM people AS p"
        },
        // _49
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name", "p.name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 未指定
                FromClosure {
                    Table { "people" }
                }
            },
            // [期待結果] to_string メンバ関数
            "SELECT name AS p.name FROM people"
        },
        // _50
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name", "p.name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.as({ "p" })
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _51
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name", "p.name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 未指定
                FromClosure {
                    Table {}
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 指定
        //         + alias_name  : 未指定
        ////////////////////////////////
        // _52
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 指定
                FromClosure {
                    Table { "people", "p" }
                }
            },
            // [期待結果] to_string メンバ関数
            "SELECT name FROM people AS p"
        },
        // _53
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 未指定
                FromClosure {
                    Table { "people" }
                }
            },
            // [期待結果] to_string メンバ関数
            "SELECT name FROM people"
        },
        // _54
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.as({ "p" })
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _55
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column { "name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 未指定
                FromClosure {
                    Table {}
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 未指定
        //         + alias_name  : 指定
        ////////////////////////////////
        // _56
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}.as({ "p.name" })
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 指定
                FromClosure {
                    Table { "people", "p" }
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _57
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}.as({ "p.name" })
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 未指定
                FromClosure {
                    Table { "people" }
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _58
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}.as({ "p.name" })
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.as({ "p" })
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _59
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}.as({ "p.name" })
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 未指定
                FromClosure {
                    Table {}
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 未指定
        //         + alias_name  : 未指定
        ////////////////////////////////
        // _60
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 指定
                FromClosure {
                    Table { "people", "p" }
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _61
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 指定
                //         + alias_name : 未指定
                FromClosure {
                    Table { "people" }
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _62
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.as({ "p" })
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _63
        {
            SelectStatement {
                SelectClosure {{
                    Column {},
                    Column {}
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 未指定
                FromClosure {
                    Table {}
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_03_HXX */
