/*!
 * @file select-closure.data-set.14.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_14_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_14_HXX

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
 * @li @c column_name : 適格
 * @li @c alias_name  : 空文字列
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
auto data_set_14() -> std::vector<SelectClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + columns[0] :
    //     + column_name : 適格
    //     + alias_name  : 空文字列
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _225
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column {}
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _226
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column {}.alias_name("")
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _227
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column {}.alias_name(" ")
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _228
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column {}.alias_name("p.name")
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + column_name : 空文字列
        ////////////////////////////////
        // _229
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column { "" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _230
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { "", "" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _231
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { "", " " }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _232
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { "", "p.name" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////
        // _233
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column { " " }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _234
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { " ", "" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _235
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { " ", " " }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _236
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { " ", "p.name" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + column_name : 適格
        ////////////////////////////////
        // _237
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column { "name" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id, name"
        },
        // _238
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { "name", "" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id, name"
        },
        // _239
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { "name", " " }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id, name"
        },
        // _240
        {
            SelectClosure {
                Column { "id", "" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { "name", "p.name" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id, name AS p.name"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_14_HXX */
