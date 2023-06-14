/*!
 * @file table.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_DATA_SET_HXX

#include <vector>

#include <sql++/identifier/table.class.h++>

#include "./table-data-set-element.class.h++"

namespace sqlxx::test
{

using sqlxx::identifier::Table;

/*!
 * @brief @c Table クラスのテストケースで使用するデータセット
 */
class TableDataSet
{
public:
    static auto for_some_test_case() -> std::vector<TableDataSetElement>;
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
 * @see sqlxx::identifier::Table              テスト対象クラス
 * @see sqlxx::identifier::Table::empty()     テスト対象メンバ関数
 * @see sqlxx::identifier::Table::to_string() テスト対象メンバ関数
 */
auto TableDataSet::for_some_test_case() -> std::vector<TableDataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _0
        {
            // [条件(1)]
            // + table :
            //     + as_closure : 未指定
            Table {},
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
            Table {}.as({ "" }),
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
            Table {}.as({ " " }),
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
            Table {}.as({ "p" }),
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 空文字列
        ////////////////////////////////////////////////////////////////////////
        // _4
        {
            // [条件(1)]
            // + table :
            //     + as_closure : 未指定
            Table { "" },
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
            Table { "" }.as({ "" }),
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
            Table { "" }.as({ " " }),
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
            Table { "" }.as({ "p" }),
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // _8
        {
            // [条件(1)]
            // + table :
            //     + as_closure : 未指定
            Table { " " },
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
            Table { " " }.as({ "" }),
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
            Table { " " }.as({ " " }),
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
            Table { " " }.as({ "p" }),
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + name : 適格
        ////////////////////////////////////////////////////////////////////////
        // _12
        {
            // [条件(1)]
            // + table :
            //     + as_closure : 未指定
            Table { "people" },
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
            Table { "people" }.as({ "" }),
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
            Table { "people" }.as({ " " }),
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
            Table { "people" }.as({ "p" }),
            // [期待結果] empty()
            false,
            // [期待結果] to_string()
            "people AS p"
        }
    };
    // clang-format on
}

} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_DATA_SET_HXX */
