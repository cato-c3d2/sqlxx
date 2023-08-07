/*!
 * @file select-closure.data-set.16.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_16_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_16_HXX

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
     * @li @c as_closure : 適格
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
    auto SelectClosureDataSet::for_some_test_case_16()
        -> std::vector<SelectClosureDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[0] :
        //     + name       : 適格
        //     + as_closure : 適格
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 未指定
            ////////////////////////////////
            // _257
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    Column {}
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _258
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    Column {}.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _259
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    Column {}.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _260
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    Column {}.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },

            ////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 空文字列
            ////////////////////////////////
            // _261
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    Column { "" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _262
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    Column { "" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _263
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    Column { "" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _264
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    Column { "" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },

            ////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////
            // _265
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    Column { " " }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _266
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    Column { " " }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _267
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    Column { " " }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },
            // _268
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    Column { " " }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            },

            ////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 適格
            ////////////////////////////////
            // _269
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    Column { "name" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name"
            },
            // _270
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    Column { "name" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name"
            },
            // _271
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    Column { "name" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name"
            },
            // _272
            {
                SelectClosure {
                    Column { "id" }.as({ "p.id" }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    Column { "name" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id, name AS p.name"
            }
        };
        // clang-format on
    }
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DETAIL__SELECT_CLOSURE_DATA_SET_16_HXX */