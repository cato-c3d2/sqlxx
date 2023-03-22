/*!
 * @file select-closure.data-set.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_00_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_00_HXX

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
 * データパターン : @n
 * @li @c columns : 未指定
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_00_a() -> std::vector<SelectClosureDataSetElement>
{
    // clang-format off
    return {
        // _0
        {
            // [条件]
            // + columns : 未指定
            SelectClosure {},
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li @c columns[1] : 未指定
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_00_b() -> std::vector<SelectClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + columns[1] : 未指定
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        ////////////////////////////////
        // [条件(1)]
        // + columns[0] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _1
        {
            SelectClosure {
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
        // _2
        {
            SelectClosure {
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
        // _3
        {
            SelectClosure {
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
        // _4
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column {}.as({ "p.id" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[0] :
        //     + column_name : 空文字列
        ////////////////////////////////
        // _5
        {
            SelectClosure {
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
        // _6
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { "", "" }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _7
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { "", " " }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _8
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { "", "p.id" }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[0] :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////
        // _9
        {
            SelectClosure {
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
        // _10
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { " ", "" }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _11
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { " ", " " }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _12
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { " ", "p.id" }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////
        // [条件(1)]
        // + columns[0] :
        //     + column_name : 適格
        ////////////////////////////////
        // _13
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 未指定
                Column { "id" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _14
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 空文字列
                Column { "id", "" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _15
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 不適格(半角スペース)
                Column { "id", " " }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id"
        },
        // _16
        {
            SelectClosure {
                // [条件(2)]
                // + columns[1] :
                //     + alias_name : 適格
                Column { "id", "p.id" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "SELECT id AS p.id"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_00_HXX */
