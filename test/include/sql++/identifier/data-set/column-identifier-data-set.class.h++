/*!
 * @file column-identifier-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_IDENTIFIER_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_IDENTIFIER_DATA_SET_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition
//
////////////////////////////////////////////////////////////////////////////////

#include <vector>

#include "./column-identifier-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace identifier
{
    /*!
     * @brief @c ColumnIdentifier クラスのテストケースで使用するデータセット
     */
    class ColumnIdentifierDataSet
    {
    public:
        /*!
        * @brief  データセットを返却する
        *
        * [ データパターン表 ] @n
        * <pre>
        * -----------------------
        * |     |    column     |
        * |     | name  |  as   |
        * =======================
        * |  _0 |   -   |   -   |
        * |  _1 |   -   |   e   |
        * |  _2 |   -   |   x   |
        * |  _3 |   -   |   o   |
        * -----------------------
        * |  _4 |   e   |   -   |
        * |  _5 |   e   |   e   |
        * |  _6 |   e   |   x   |
        * |  _7 |   e   |   o   |
        * -----------------------
        * |  _8 |   x   |   -   |
        * |  _9 |   x   |   e   |
        * | _10 |   x   |   x   |
        * | _11 |   x   |   o   |
        * -----------------------
        * | _12 |   o   |   -   |
        * | _13 |   o   |   e   |
        * | _14 |   o   |   x   |
        * | _15 |   o   |   o   |
        * -----------------------
        * </pre>
        *
        * [[ 凡例 ]] @n
        * @li o ... 指定(適格)
        * @li e ... 指定(不適格(空文字列))
        * @li x ... 指定(不適格(半角スペース))
        * @li - ... 未指定
        *
        * @return データセット
        *
        * @see sqlxx::identifier::ColumnIdentifier              テスト対象クラス
        * @see sqlxx::identifier::ColumnIdentifier::empty()     テスト対象メンバ関数
        * @see sqlxx::identifier::ColumnIdentifier::to_string() テスト対象メンバ関数
        */
        static auto for_some_test_case()
            -> std::vector<ColumnIdentifierDataSetElement>;
    };
} // namespace identifier
} // namespace sqlxx::test

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/identifier/column-identifier.class.h++>

namespace sqlxx::test
{
inline namespace identifier
{
    using sqlxx::ColumnIdentifier;

    auto ColumnIdentifierDataSet::for_some_test_case()
        -> std::vector<ColumnIdentifierDataSetElement>
    {
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + column :
            //     + name : 未指定
            ////////////////////////////////////////////////////////////////////
            // _0
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 未指定
                ColumnIdentifier {},
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _1
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 空文字列
                ColumnIdentifier {}.as({ "" }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _2
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 不適格(半角スペース)
                ColumnIdentifier {}.as({ " " }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _3
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 適格
                ColumnIdentifier {}.as({ "p.id" }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + column :
            //     + name : 空文字列
            ////////////////////////////////////////////////////////////////////
            // _4
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 未指定
                ColumnIdentifier { "" },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _5
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 空文字列
                ColumnIdentifier { "" }.as({ "" }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _6
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 不適格(半角スペース)
                ColumnIdentifier { "" }.as({ " " }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _7
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 適格
                ColumnIdentifier { "" }.as({ "p.id" }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + column :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////////////////////////////////////////
            // _8
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 未指定
                ColumnIdentifier { " " },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _9
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 空文字列
                ColumnIdentifier { " " }.as({ "" }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _10
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 不適格(半角スペース)
                ColumnIdentifier { " " }.as({ " " }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _11
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 適格
                ColumnIdentifier { " " }.as({ "p.id" }),
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + column :
            //     + name : 適格
            ////////////////////////////////////////////////////////////////////
            // _12
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 未指定
                ColumnIdentifier { "id" },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "id"
            },
            // _13
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 空文字列
                ColumnIdentifier { "id" }.as({ "" }),
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "id"
            },
            // _14
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 不適格(半角スペース)
                ColumnIdentifier { "id" }.as({ " " }),
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "id"
            },
            // _15
            {
                // [条件(1)]
                // + column :
                //     + as_closure : 適格
                ColumnIdentifier { "id" }.as({ "p.id" }),
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "id AS p.id"
            }
        };
        // clang-format on
    }
} // namespace identifier
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_IDENTIFIER_DATA_SET_HXX */
