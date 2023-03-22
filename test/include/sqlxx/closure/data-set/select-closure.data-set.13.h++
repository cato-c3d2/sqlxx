/*!
 * @file select-closure.data-set.13.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_13_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_13_HXX

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
 * @li @c alias_name  : 未指定
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
auto data_set_13() -> std::vector<SelectClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + columns[0] :
    //     + column_name : 適格
    //     + alias_name  : 未指定
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _209
        {
            SelectClosure {
                Column { "id" },
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
        // _210
        {
            SelectClosure {
                Column { "id" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column {}.as({ "" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _211
        {
            SelectClosure {
                Column { "id" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column {}.as({ " " })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _212
        {
            SelectClosure {
                Column { "id" },
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column {}.as({ "p.name" })
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
        // _213
        {
            SelectClosure {
                Column { "id" },
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
        // _214
        {
            SelectClosure {
                Column { "id" },
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
        // _215
        {
            SelectClosure {
                Column { "id" },
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
        // _216
        {
            SelectClosure {
                Column { "id" },
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
        // _217
        {
            SelectClosure {
                Column { "id" },
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
        // _218
        {
            SelectClosure {
                Column { "id" },
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
        // _219
        {
            SelectClosure {
                Column { "id" },
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
        // _220
        {
            SelectClosure {
                Column { "id" },
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
        // _221
        {
            SelectClosure {
                Column { "id" },
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
        // _222
        {
            SelectClosure {
                Column { "id" },
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
        // _223
        {
            SelectClosure {
                Column { "id" },
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
        // _224
        {
            SelectClosure {
                Column { "id" },
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

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_13_HXX */
