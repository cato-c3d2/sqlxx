/*!
 * @file select-statement.data-set.04.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_04_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_04_HXX

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
 * データパターン : その他
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectStatement              テスト対象クラス
 * @see sqlxx::closure::SelectStatement::to_string() テスト対象メンバ関数
 */
auto data_set_04() -> std::vector<SelectStatementDataSetElement>
{
    // clang-format off
    return {
        // _64
        {
            // [条件]
            // + select_closure : 未指定
            // + from_closure   : 未指定
            SelectStatement {},
            // [期待結果] to_string メンバ関数
            ""
        },
        // _65
        {
            // [条件]
            // + select_closure :
            //     + columns  : 未指定
            // + from_closure : 未指定
            SelectStatement {
                SelectClosure {}
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _66
        {
            // [条件]
            // + select_closure : 未指定
            // + from_closure   :
            //     + table      : 未指定
            SelectStatement {}.from(FromClosure {}),
            // [期待結果] to_string メンバ関数
            ""
        },
        // _67
        {
            // [条件]
            // + select_closure :
            //     + columns : 未指定
            // + from_closure :
            //     + table   : 未指定
            SelectStatement {
                SelectClosure {},
                FromClosure {}
            },
            // [期待結果] to_string メンバ関数
            ""
        },
        // _68
        {
            // [条件]
            // + select_closure :
            //     + columns[0] :
            //         + name       : 不適格
            //         + alias_name : 不適格
            //     + columns[1] :
            //         + name       : 不適格
            //         + alias_name : 不適格
            // + from_closure :
            //     + table :
            //         + name       : 不適格
            //         + alias_name : 不適格
            SelectStatement {
                SelectClosure {{
                    Column { " ", "," },
                    Column { ".", ";" }
                }},
                FromClosure {
                    Table { "\'", "\\" }
                }
            },
            // [期待結果] to_string メンバ関数
            ""
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_04_HXX */
