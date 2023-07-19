/*!
 * @file select-closure.data-set.14.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_14_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_14_HXX

#include <vector>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column.class.h++>

#include "../select-closure-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace
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
     * @li @c as_closure : 空文字列
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
    auto SelectClosureDataSet::for_some_test_case_14()
        -> std::vector<SelectClosureDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[0] :
        //     + name       : 適格
        //     + as_closure : 空文字列
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 未指定
            ////////////////////////////////
            // _225
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _226
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _227
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _228
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _229
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _230
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _231
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _232
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _233
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _234
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _235
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _236
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _237
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _238
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _239
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
            // _240
            {
                SelectClosure {
                    Column { "id" }.as({ "" }),
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
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_14_HXX */
