/*!
 * @file select-closure-data-set.class-member.15.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_15_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_15_HXX

#include <vector>

#include <sql++/clause/select-clause.class.h++>
#include <sql++/identifier/column-identifier.class.h++>

#include "../select-closure-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace closure
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    using sqlxx::ColumnIdentifier;
    using sqlxx::SelectClause;

    /*!
     * @brief データセットを返却する
     *
     * データパターン :
     *
     * @c columns[0] : @n
     * @li @c name       : 適格
     * @li @c as_closure : 不適格(半角スペース)
     *
     * @c columns[1] : @n
     * @li @c name       : 未指定, 空文字列, 不適格(半角スペース) or 適格
     * @li @c as_closure : 未指定, 空文字列, 不適格(半角スペース) or 適格
     *
     * @return データセット
     *
     * @see sqlxx::clause::SelectClause              テスト対象クラス
     * @see sqlxx::clause::SelectClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::SelectClause::to_string() テスト対象メンバ関数
     */
    auto SelectClosureDataSet::for_some_test_case_15()
        -> std::vector<SelectClosureDataSetElement>
    {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + columns[0] :
        //     + name       : 適格
        //     + as_closure : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 未指定
            ////////////////////////////////////////////////////////////////////
            // _241
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier {}
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _242
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier {}.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _243
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier {}.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _244
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier {}.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 空文字列
            ////////////////////////////////////////////////////////////////////
            // _245
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { "" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _246
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { "" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _247
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { "" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _248
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier { "" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////////////////////////////////////////
            // _249
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { " " }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _250
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { " " }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _251
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { " " }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },
            // _252
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier { " " }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id"
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(1)]
            // + columns[1] :
            //     + name : 適格
            ////////////////////////////////////////////////////////////////////
            // _253
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 未指定
                    ColumnIdentifier { "name" }
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id, name"
            },
            // _254
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 空文字列
                    ColumnIdentifier { "name" }.as({ "" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id, name"
            },
            // _255
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 不適格(半角スペース)
                    ColumnIdentifier { "name" }.as({ " " })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id, name"
            },
            // _256
            {
                SelectClause {
                    ColumnIdentifier { "id" }.as({ " " }),
                    // [条件(2)]
                    // + columns[1] :
                    //     + as_closure : 適格
                    ColumnIdentifier { "name" }.as({ "p.name" })
                },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "SELECT id, name AS p.name"
            }
        };
        // clang-format on
    }
} // namespace closure
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__DEFINITION__SELECT_CLOSURE_DATA_SET_CLASS_MEMBER_15_HXX */
