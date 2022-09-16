/*!
 * @file select-closure.data-set.09.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_09_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_09_HXX

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
 * データパターン :
 *
 * @c columns[0] : @n
 * @li @c column_name : 不適格(半角スペース)
 * @li @c alias_name  : 未指定
 *
 * @c columns[1] : @n
 * @li @c column_name : 未指定, 空文字列, 不適格(半角スペース) or 適格
 * @li @c alias_name  : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string_09() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + columns[0] :
        //     + column_name : 不適格(半角スペース)
        //     + alias_name  : 未指定
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _145
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 未指定
                Column {}
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },
        // _146
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 空文字列
                Column {}.alias_name("")
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },
        // _147
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 不適格(半角スペース)
                Column {}.alias_name(" ")
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },
        // _148
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 適格
                Column {}.alias_name("p.name")
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 空文字列
        ////////////////////////////////
        // _149
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 未指定
                Column { "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },
        // _150
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 空文字列
                Column { "", "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },
        // _151
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 不適格(半角スペース)
                Column { "", " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },
        // _152
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 適格
                Column { "", "p.name" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , "
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////
        // _153
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 未指定
                Column { " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  ,  "
        },
        // _154
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 空文字列
                Column { " ", "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  ,  "
        },
        // _155
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 不適格(半角スペース)
                Column { " ", " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  ,   AS  "
        },
        // _156
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 適格
                Column { " ", "p.name" }
            },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  ,   AS p.name"
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 適格
        ////////////////////////////////
        // _157
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 未指定
                Column { "name" }
            },
            // SQL 文字列 : 適格
            // "SELECT name"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , name"
        },
        // _158
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 空文字列
                Column { "name", "" }
            },
            // SQL 文字列 : 適格
            // "SELECT name"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , name"
        },
        // _159
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 不適格(半角スペース)
                Column { "name", " " }
            },
            // SQL 文字列 : 適格
            // "SELECT name"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , name AS  "
        },
        // _160
        {
            SelectClosure {
                Column { " " },
                // + alias_name : 適格
                Column { "name", "p.name" }
            },
            // SQL 文字列 : 適格
            // "SELECT name AS p.name"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT  , name AS p.name"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_09_HXX */
