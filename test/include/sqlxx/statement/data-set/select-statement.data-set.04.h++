/*!
 * @file select-statement.data-set.04.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_04_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_04_HXX

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
 * データパターン : その他
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectStatement              テスト対象クラス
 * @see sqlxx::closure::SelectStatement::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string_04() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + select_closure : 未指定
        // + from_closure   : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _64
        {
            SelectStatement {},
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + select_closure :
        //     + columns  : 未指定
        // + from_closure : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _65
        {
            SelectStatement {
                SelectClosure {}
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + select_closure : 未指定
        // + from_closure   :
        //     + table      : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _66
        {
            SelectStatement {}.from(FromClosure {}),
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + select_closure :
        //     + columns : 未指定
        // + from_closure :
        //     + table   : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _67
        {
            SelectStatement {
                SelectClosure {},
                FromClosure {}
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + select_closure :
        //     + columns[0] :
        //         + column_name : 不適格
        //         + alias_name  : 不適格
        //     + columns[1] :
        //         + column_name : 不適格
        //         + alias_name  : 不適格
        // + from_closure :
        //     + table :
        //         + table_name  : 不適格
        //         + alias_name  : 不適格
        ////////////////////////////////////////////////////////////////////////
        // _68
        {
            SelectStatement {
                SelectClosure {{
                    Column { " ", "," },
                    Column { ".", ";" }
                }},
                FromClosure {
                    Table { "\'", "\\" }
                }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT   AS ,, . AS ; FROM ' AS \\"
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_04_HXX */
