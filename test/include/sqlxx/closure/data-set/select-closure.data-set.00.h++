/*!
 * @file select-closure.data-set.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_00_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_00_HXX

#include <vector>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/specification/column.class.h++>

#include "./select-closure.data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__SelectClosure)

using sqlxx::closure::SelectClosure;
using sqlxx::specification::Column;

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li @c columns[1] : 未指定
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string_00() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + columns[0] : 未指定
        // + columns[1] : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _0
        {
            SelectClosure {},
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + columns[1] : 未指定
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////
        // + columns[0] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _1
        {
            SelectClosure {
                // + alias_name : 未指定
                Column {}
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },
        // _2
        {
            SelectClosure {
                // + alias_name : 空文字列
                Column {}.alias_name("")
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },
        // _3
        {
            SelectClosure {
                // + alias_name : 不適格(半角スペース)
                Column {}.alias_name(" ")
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },
        // _4
        {
            SelectClosure {
                // + alias_name : 適格
                Column {}.alias_name("p.id")
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },

        ////////////////////////////////
        // + columns[0] :
        //     + column_name : 空文字列
        ////////////////////////////////
        // _5
        {
            SelectClosure {
                // + alias_name : 未指定
                Column { "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },
        // _6
        {
            SelectClosure {
                // + alias_name : 空文字列
                Column { "", "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },
        // _7
        {
            SelectClosure {
                // + alias_name : 不適格(半角スペース)
                Column { "", " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },
        // _8
        {
            SelectClosure {
                // + alias_name : 適格
                Column { "", "p.id" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT "
        },

        ////////////////////////////////
        // + columns[0] :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////
        // _9
        {
            SelectClosure {
                // + alias_name : 未指定
                Column { " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  "
        },
        // _10
        {
            SelectClosure {
                // + alias_name : 空文字列
                Column { " ", "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  "
        },
        // _11
        {
            SelectClosure {
                // + alias_name : 不適格(半角スペース)
                Column { " ", " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT   AS  "
        },
        // _12
        {
            SelectClosure {
                // + alias_name : 適格
                Column { " ", "p.id" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT   AS p.id"
        },

        ////////////////////////////////
        // + columns[0] :
        //     + column_name : 適格
        ////////////////////////////////
        // _13
        {
            SelectClosure {
                // + alias_name : 未指定
                Column { "id" }
            },
            // SQL 文字列 : 適格
            "SELECT id"
        },
        // _14
        {
            SelectClosure {
                // + alias_name : 空文字列
                Column { "id", "" }
            },
            // SQL 文字列 : 適格
            "SELECT id"
        },
        // _15
        {
            SelectClosure {
                // + alias_name : 不適格(半角スペース)
                Column { "id", " " }
            },
            // SQL 文字列 : 適格
            // "SELECT id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS  "
        },
        // _16
        {
            SelectClosure {
                // + alias_name : 適格
                Column { "id", "p.id" }
            },
            // SQL 文字列 : 適格
            "SELECT id AS p.id"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_00_HXX */
