/*!
 * @file select-closure.data-set.13.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_13_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_13_HXX

#include <vector>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column.class.h++>

#include "../select-closure-data-set-element.class.h++"

namespace sqlxx::test
{

using sqlxx::closure::SelectClosure;
using sqlxx::identifier::Column;

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c columns[0] : @n
 * @li @c name       : 適格
 * @li @c as_closure : 未指定
 *
 * @c columns[1] : @n
 * @li @c name       : 未指定, 空文字列, 不適格(半角スペース) or 適格
 * @li @c as_closure : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto SelectClosureDataSet::for_some_test_case_13()
    -> std::vector<SelectClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + columns[0] :
    //     + name       : 適格
    //     + as_closure : 未指定
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + name : 未指定
        ////////////////////////////////
        // _209
        {
            SelectClosure {
                Column { "id" },
                // [条件(2)]
                // + columns[1] :
                //     + as_closure : 未指定
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
                //     + as_closure : 空文字列
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
                //     + as_closure : 不適格(半角スペース)
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
                //     + as_closure : 適格
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
        //     + name : 空文字列
        ////////////////////////////////
        // _213
        {
            SelectClosure {
                Column { "id" },
                // [条件(2)]
                // + columns[1] :
                //     + as_closure : 未指定
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
                //     + as_closure : 空文字列
                Column { "" }.as({ "" })
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
                //     + as_closure : 不適格(半角スペース)
                Column { "" }.as({ " " })
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
                //     + as_closure : 適格
                Column { "" }.as({ "p.name" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + name : 不適格(半角スペース)
        ////////////////////////////////
        // _217
        {
            SelectClosure {
                Column { "id" },
                // [条件(2)]
                // + columns[1] :
                //     + as_closure : 未指定
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
                //     + as_closure : 空文字列
                Column { " " }.as({ "" })
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
                //     + as_closure : 不適格(半角スペース)
                Column { " " }.as({ " " })
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
                //     + as_closure : 適格
                Column { " " }.as({ "p.name" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[1] :
        //     + name : 適格
        ////////////////////////////////
        // _221
        {
            SelectClosure {
                Column { "id" },
                // [条件(2)]
                // + columns[1] :
                //     + as_closure : 未指定
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
                //     + as_closure : 空文字列
                Column { "name" }.as({ "" })
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
                //     + as_closure : 不適格(半角スペース)
                Column { "name" }.as({ " " })
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
                //     + as_closure : 適格
                Column { "name" }.as({ "p.name" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id, name AS p.name"
        }
    };
    // clang-format on
}

} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_13_HXX */
