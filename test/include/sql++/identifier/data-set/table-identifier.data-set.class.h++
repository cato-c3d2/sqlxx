/*!
 * @file table-identifier.data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_IDENTIFIER_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_IDENTIFIER_DATA_SET_HXX

#include <vector>

#include <sql++/identifier/table-identifier.class.h++>

#include "./table-identifier-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace identifier
{
    using sqlxx::TableIdentifier;

    /*!
     * @brief @c TableIdentifier クラスのテストケースで使用するデータセット
     */
    class TableIdentifierDataSet
    {
    public:
        static auto for_some_test_case()
            -> std::vector<TableIdentifierDataSetElement>;
    };

    /*!
     * @brief  データセットを返却する
     *
     * [ データパターン表 ] @n
     * <pre>
     * -----------------------
     * |     |     table     |
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
     * @see sqlxx::identifier::TableIdentifier              テスト対象クラス
     * @see sqlxx::identifier::TableIdentifier::empty()     テスト対象メンバ関数
     * @see sqlxx::identifier::TableIdentifier::to_string() テスト対象メンバ関数
     */
    auto TableIdentifierDataSet::for_some_test_case()
        -> std::vector<TableIdentifierDataSetElement>
    {
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + table :
            //     + name : 未指定
            ////////////////////////////////////////////////////////////////////
            // _0
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                TableIdentifier {},
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _1
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                TableIdentifier {}.as({ "" }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _2
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                TableIdentifier {}.as({ " " }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _3
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                TableIdentifier {}.as({ "p" }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + table :
            //     + name : 空文字列
            ////////////////////////////////////////////////////////////////////
            // _4
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                TableIdentifier { "" },
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _5
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                TableIdentifier { "" }.as({ "" }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _6
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                TableIdentifier { "" }.as({ " " }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _7
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                TableIdentifier { "" }.as({ "p" }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + table :
            //     + name : 不適格(半角スペース)
            ////////////////////////////////////////////////////////////////////
            // _8
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                TableIdentifier { " " },
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _9
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                TableIdentifier { " " }.as({ "" }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _10
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                TableIdentifier { " " }.as({ " " }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },
            // _11
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                TableIdentifier { " " }.as({ "p" }),
                // [期待結果] empty()
                true,
                // [期待結果] to_string()
                ""
            },

            ////////////////////////////////////////////////////////////////////
            // [条件(0)]
            // + table :
            //     + name : 適格
            ////////////////////////////////////////////////////////////////////
            // _12
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                TableIdentifier { "people" },
                // [期待結果] empty()
                false,
                // [期待結果] to_string()
                "people"
            },
            // _13
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                TableIdentifier { "people" }.as({ "" }),
                // [期待結果] empty()
                false,
                // [期待結果] to_string()
                "people"
            },
            // _14
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                TableIdentifier { "people" }.as({ " " }),
                // [期待結果] empty()
                false,
                // [期待結果] to_string()
                "people"
            },
            // _15
            {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                TableIdentifier { "people" }.as({ "p" }),
                // [期待結果] empty()
                false,
                // [期待結果] to_string()
                "people AS p"
            }
        };
        // clang-format on
    }
} // namespace identifier
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_IDENTIFIER_DATA_SET_HXX */
