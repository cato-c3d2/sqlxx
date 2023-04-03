/*!
 * @file select-closure.data-set.04.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_04_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_04_HXX

#include <vector>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column.class.h++>

#include "./select-closure-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__SelectClosure)

using sqlxx::closure::SelectClosure;
using sqlxx::identifier::Column;

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c columns[0] : @n
 * @li @c name       : 未指定
 * @li @c alias_name : 適格
 *
 * @c columns[1] : @n
 * @li @c name       : 未指定, 空文字列, 不適格(半角スペース) or 適格
 * @li @c alias_name : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_04() -> std::vector<SelectClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + columns[0] :
    //     + name       : 未指定
    //     + alias_name : 適格
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + name : 未指定
        ////////////////////////////////
        // _65
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column {}
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _66
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column {}.as({ "" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _67
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column {}.as({ " " })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _68
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column {}.as({ "p.name" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + name : 空文字列
        ////////////////////////////////
        // _69
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column { "" }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _70
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { "" }.as({ "" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _71
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { "" }.as({ " " })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _72
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { "" }.as({ "p.name" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + name : 不適格(半角スペース)
        ////////////////////////////////
        // _73
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column { " " }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _74
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { " " }.as({ "" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _75
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { " " }.as({ " " })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _76
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { " " }.as({ "p.name" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + name : 適格
        ////////////////////////////////
        // _77
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column { "name" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT name"
        },
        // _78
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { "name" }.as({ "" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT name"
        },
        // _79
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { "name" }.as({ " " })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT name"
        },
        // _80
        {
            SelectClosure {
                Column {}.as({ "p.id" }),
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { "name" }.as({ "p.name" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT name AS p.name"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_04_HXX */
