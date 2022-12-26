/*!
 * @file select-closure.data-set.03.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_03_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_03_HXX

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
 * @li @c alias_name  : 不適格(半角スペース)
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
auto data_set_for_to_string_03() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + columns[0] :
        //     + column_name : 未指定
        //     + alias_name  : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _49
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 未指定
                Column {}
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _50
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 空文字列
                Column {}.alias_name("")
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _51
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 不適格(半角スペース)
                Column {}.alias_name(" ")
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _52
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 適格
                Column {}.alias_name("p.name")
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 空文字列
        ////////////////////////////////
        // _53
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 未指定
                Column { "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _54
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 空文字列
                Column { "", "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _55
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 不適格(半角スペース)
                Column { "", " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _56
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 適格
                Column { "", "p.name" }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////
        // _57
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 未指定
                Column { " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _58
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 空文字列
                Column { " ", "" }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _59
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 不適格(半角スペース)
                Column { " ", " " }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _60
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 適格
                Column { " ", "p.name" }
            },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 適格
        ////////////////////////////////
        // _61
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 未指定
                Column { "name" }
            },
            // SQL 文字列 : 適格
            "SELECT name"
        },
        // _62
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 空文字列
                Column { "name", "" }
            },
            // SQL 文字列 : 適格
            "SELECT name"
        },
        // _63
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 不適格(半角スペース)
                Column { "name", " " }
            },
            // SQL 文字列 : 適格
            "SELECT name"
        },
        // _64
        {
            SelectClosure {
                Column {}.alias_name(" "),
                // + alias_name : 適格
                Column { "name", "p.name" }
            },
            // SQL 文字列 : 適格
            "SELECT name AS p.name"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_03_HXX */