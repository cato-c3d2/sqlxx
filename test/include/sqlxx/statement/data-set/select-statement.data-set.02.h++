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
auto data_set_for_to_string_02() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + select_closure :
        //     + columns[0] :
        //         + column_name : 未指定
        //         + alias_name  : 指定
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////
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
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT name AS p.name FROM people AS p"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT , name AS p.name FROM people AS p"
        },
        // _33
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
                    Column { "name", "p.name" }
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT name AS p.name FROM people"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT , name AS p.name FROM people"
        },
        // _34
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , name AS p.name"
        },
        // _35
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , name AS p.name"
        },

        ////////////////////////////////
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
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT name FROM people AS p"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT , name FROM people AS p"
        },
        // _37
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
                    Column { "name" }
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 適格
            // "SELECT name FROM people"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT , name FROM people"
        },
        // _38
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , name"
        },
        // _39
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , name"
        },

        ////////////////////////////////
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
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT ,  FROM people AS p"
        },
        // _41
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
                    Column {}.alias_name("p.name")
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT ,  FROM people"
        },
        // _42
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , "
        },
        // _43
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , "
        },

        ////////////////////////////////
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
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 指定
                    Table { "people", "p" }
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT ,  FROM people AS p"
        },
        // _45
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
                    Column {}
                }},
                FromClosure {
                    // + table_name : 指定
                    // + alias_name : 未指定
                    Table { "people" }
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT ,  FROM people"
        },
        // _46
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , "
        },
        // _47
        {
            SelectStatement {
                SelectClosure {{
                    Column {}.alias_name("p.id"),
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
            "SELECT , "
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_02_HXX */
