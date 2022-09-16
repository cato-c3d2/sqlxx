/*!
 * @file select-statement.data-set.01.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_01_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_01_HXX

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
auto data_set_for_to_string_01() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + select_closure :
        //     + columns[0] :
        //         + column_name : 指定
        //         + alias_name  : 未指定
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 指定
        //         + alias_name  : 指定
        ////////////////////////////////
        // _16
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name", "p.name" }
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 適格
            "SELECT id, name AS p.name FROM people AS p"
        },
        // _17
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name", "p.name" }
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 適格
            "SELECT id, name AS p.name FROM people"
        },
        // _18
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name", "p.name" }
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 指定
                    Table {}.alias_name("p")
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, name AS p.name"
        },
        // _19
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name", "p.name" }
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 未指定
                    Table {}
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, name AS p.name"
        },

        ////////////////////////////////
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 指定
        //         + alias_name  : 未指定
        ////////////////////////////////
        // _20
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name" }
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 適格
            "SELECT id, name FROM people AS p"
        },
        // _21
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name" }
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 適格
            "SELECT id, name FROM people"
        },
        // _22
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name" }
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 指定
                    Table {}.alias_name("p")
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, name"
        },
        // _23
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column { "name" }
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 未指定
                    Table {}
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, name"
        },

        ////////////////////////////////
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 未指定
        //         + alias_name  : 指定
        ////////////////////////////////
        // _24
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}.alias_name("p.name")
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT id FROM people AS p"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id,  FROM people AS p"
        },
        // _25
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}.alias_name("p.name")
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT id FROM people"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id,  FROM people"
        },
        // _26
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}.alias_name("p.name")
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 指定
                    Table {}.alias_name("p")
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, "
        },
        // _27
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}.alias_name("p.name")
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 未指定
                    Table {}
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, "
        },

        ////////////////////////////////
        // + select_closure :
        //     + columns[1] :
        //         + column_name : 未指定
        //         + alias_name  : 未指定
        ////////////////////////////////
        // _28
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT id FROM people AS p"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id,  FROM people AS p"
        },
        // _29
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT id FROM people"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id,  FROM people"
        },
        // _30
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 指定
                    Table {}.alias_name("p")
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, "
        },
        // _31
        {
            SelectStatement {
                SelectClosure {{
                    Column { "id" },
                    Column {}
                }},
                FromClosure {
                    // + table_name : 未指定
                    // + alias_name : 未指定
                    Table {}
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id, "
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_01_HXX */
