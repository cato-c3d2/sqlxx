/*!
 * @file select-closure.data-set.04.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_04_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_04_HXX

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
 * @li @c column_name : 未指定
 * @li @c alias_name  : 適格
 *
 * @c columns[1] : @n
 * @li @c column_name : 未指定, 空文字列, 不適格(半角スペース) or 適格
 * @li @c alias_name  : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string_04() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + columns[0] :
        //     + column_name : 未指定
        //     + alias_name  : 適格
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _65
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 未指定
                Column {}
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _66
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 空文字列
                Column {}.alias_name("")
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _67
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 不適格(半角スペース)
                Column {}.alias_name(" ")
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _68
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 適格
                Column {}.alias_name("p.name")
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 空文字列
        ////////////////////////////////
        // _69
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 未指定
                Column { "" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _70
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 空文字列
                Column { "", "" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _71
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 不適格(半角スペース)
                Column { "", " " }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _72
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 適格
                Column { "", "p.name" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////
        // _73
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 未指定
                Column { " " }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _74
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 空文字列
                Column { " ", "" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _75
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 不適格(半角スペース)
                Column { " ", " " }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _76
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 適格
                Column { " ", "p.name" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 適格
        ////////////////////////////////
        // _77
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 未指定
                Column { "name" }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "SELECT name"
        },
        // _78
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 空文字列
                Column { "name", "" }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "SELECT name"
        },
        // _79
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 不適格(半角スペース)
                Column { "name", " " }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "SELECT name"
        },
        // _80
        {
            SelectClosure {
                Column {}.alias_name("p.id"),
                // + alias_name : 適格
                Column { "name", "p.name" }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "SELECT name AS p.name"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_04_HXX */
