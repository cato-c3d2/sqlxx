/*!
 * @file select-closure-data-set.class-member.11.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_11_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_11_HXX

#include <vector>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column-identifier.class.h++>

#include "../select-closure-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace
{
    using sqlxx::ColumnIdentifier;
    using sqlxx::SelectClosure;

    /*!
     * @brief データセットを返却する
     *
     * データパターン :
     *
     * @c columns[0] : @n
     * @li @c name       : 不適格(半角スペース)
     * @li @c as_closure : 不適格(半角スペース)
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
    auto SelectClosureDataSet::for_some_test_case_11()
        -> std::vector<SelectClosureDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[0] :
        //     + name       : 不適格(半角スペース)
        //     + as_closure : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 未指定
            ////////////////////////////////
            // _177
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier {}
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _178
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier {}.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _179
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier {}.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _180
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier {}.as({ "p.name" })
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
            // _181
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { "" }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _182
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { "" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _183
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { "" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _184
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier { "" }.as({ "p.name" })
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
            // _185
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { " " }
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _186
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { " " }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _187
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { " " }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _188
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier { " " }.as({ "p.name" })
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
            // _189
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { "name" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name"
            },
            // _190
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { "name" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name"
            },
            // _191
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { "name" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name"
            },
            // _192
            {
                SelectClosure {
                    ColumnIdentifier { " " }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier { "name" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT name AS p.name"
            }
        };
        // clang-format on
    }
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_11_HXX */
