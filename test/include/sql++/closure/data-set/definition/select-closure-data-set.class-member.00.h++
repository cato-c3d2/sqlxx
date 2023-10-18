/*!
 * @file select-closure-data-set.class-member.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_00_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_00_HXX

#include <vector>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column-identifier.class.h++>

#include "../select-closure-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace closure
{
    using sqlxx::ColumnIdentifier;
    using sqlxx::SelectClosure;

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
    auto SelectClosureDataSet::for_some_test_case_00_a()
        -> std::vector<SelectClosureDataSetElement>
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
    auto SelectClosureDataSet::for_some_test_case_00_b()
        -> std::vector<SelectClosureDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[1] : 未指定
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 未指定
            ////////////////////////////////
            // _1
            {
                SelectClosure {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_closure : 未指定
                    ColumnIdentifier {}
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
                    // + columns[0] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier {}.as({ "" })
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
                    // + columns[0] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier {}.as({ " " })
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
                    // + columns[0] :
                    //     + as_closure : 適格
                    ColumnIdentifier {}.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 空文字列
            ////////////////////////////////
            // _5
            {
                SelectClosure {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { "" }
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
                    // + columns[0] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { "" }.as({ "" })
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
                    // + columns[0] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { "" }.as({ " " })
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
                    // + columns[0] :
                    //     + as_closure : 適格
                    ColumnIdentifier { "" }.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////
            // _9
            {
                SelectClosure {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { " " }
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
                    // + columns[0] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { " " }.as({ "" })
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
                    // + columns[0] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { " " }.as({ " " })
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
                    // + columns[0] :
                    //     + as_closure : 適格
                    ColumnIdentifier { " " }.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////
            // [条件(1)]
            // + columns[0] :
            //     + name : 適格
            ////////////////////////////////
            // _13
            {
                SelectClosure {
                    // [条件(2)]
                    // + columns[0] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { "id" }
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
                    // + columns[0] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { "id" }.as({ "" })
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
                    // + columns[0] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { "id" }.as({ " " })
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
                    // + columns[0] :
                    //     + as_closure : 適格
                    ColumnIdentifier { "id" }.as({ "p.id" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id AS p.id"
            }
        };
        // clang-format on
    }
} // namespace closure
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_00_HXX */
