/*!
 * @file select-statement.data-set.02.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_02_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_02_HXX

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
 * @li @c column_name : 未指定
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
auto data_set_02() -> std::vector<DataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + select_closure :
    //     + columns[0] :
    //         + column_name : 未指定
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
        // _32
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _33
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _34
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _35
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _36
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _37
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _38
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _39
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _40
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            ""
        },
        // _41
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            ""
        },
        // _42
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _43
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _44
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _45
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _46
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
        // _47
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_02_HXX */
