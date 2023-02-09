/*!
 * @file select-statement.data-set.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_00_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_00_HXX

#include <vector>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>
#include <sql++/specification/column.class.h++>
#include <sql++/specification/table.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "./select-statement.data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__statement)

BOOST_AUTO_TEST_SUITE(class__SelectStatement)

using sqlxx::closure::FromClosure;
using sqlxx::closure::SelectClosure;
using sqlxx::specification::Column;
using sqlxx::specification::Table;
using sqlxx::statement::SelectStatement;

/*!
 * @brief  データセットを返却する
 *
 * データパターン :
 *
 * @c select_closure :
 *
 * @c columns[0] : @n
 * @li @c column_name : 指定
 * @li @c alias_name  : 指定
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
auto data_set_00() -> std::vector<DataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + select_closure :
    //     + columns[0] :
    //         + column_name : 指定
    //         + alias_name  : 指定
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
        // _0
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
            "SELECT id AS p.id, name AS p.name FROM people AS p"
        },
        // _1
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
            "SELECT id AS p.id, name AS p.name FROM people"
        },
        // _2
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
                    Column { "name", "p.name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.alias_name("p")
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _3
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
        // _4
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
            "SELECT id AS p.id, name FROM people AS p"
        },
        // _5
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
            "SELECT id AS p.id, name FROM people"
        },
        // _6
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
                    Column { "name" }
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.alias_name("p")
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _7
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
        // _8
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
                    Column {}.alias_name("p.name")
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
            "SELECT id AS p.id FROM people AS p"
        },
        // _9
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
                    Column {}.alias_name("p.name")
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
            "SELECT id AS p.id FROM people"
        },
        // _10
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
                    Column {}.alias_name("p.name")
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.alias_name("p")
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _11
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
                    Column {}.alias_name("p.name")
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
        // _12
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
            "SELECT id AS p.id FROM people AS p"
        },
        // _13
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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
            "SELECT id AS p.id FROM people"
        },
        // _14
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
                    Column {}
                }},
                // [条件(2)]
                // + from_closure :
                //     + table :
                //         + table_name : 未指定
                //         + alias_name : 指定
                FromClosure {
                    Table {}.alias_name("p")
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _15
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id", "p.id" },
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

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_00_HXX */
