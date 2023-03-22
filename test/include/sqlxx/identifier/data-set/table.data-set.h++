/*!
 * @file table.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_DATA_SET_HXX

#include <vector>

#include <sql++/identifier/table.class.h++>

#include "./table-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__identifier)

BOOST_AUTO_TEST_SUITE(class__Table)

using sqlxx::identifier::Table;

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::identifier::Table              テスト対象クラス
 * @see sqlxx::identifier::Table::empty()     テスト対象メンバ関数
 * @see sqlxx::identifier::Table::to_string() テスト対象メンバ関数
 */
auto data_set() -> std::vector<TableDataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + table_name : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _0
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 未指定
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
            //     + alias_name : 空文字列
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
            //     + alias_name : 不適格(半角スペース)
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
            //     + alias_name : 適格
            Table {}.as({ "p" }),
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + table_name : 空文字列
        ////////////////////////////////////////////////////////////////////////
        // _4
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 未指定
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
            //     + alias_name : 空文字列
            Table { "", "" },
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },
        // _6
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 不適格(半角スペース)
            Table { "", " " },
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },
        // _7
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 適格
            Table { "", "p" },
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + table_name : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // _8
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 未指定
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
            //     + alias_name : 空文字列
            Table { " ", "" },
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },
        // _10
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 不適格(半角スペース)
            Table { " ", " " },
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },
        // _11
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 適格
            Table { " ", "p" },
            // [期待結果] empty()
            true,
            // [期待結果] to_string()
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + table :
        //     + table_name : 適格
        ////////////////////////////////////////////////////////////////////////
        // _12
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 未指定
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
            //     + alias_name : 空文字列
            Table { "people", "" },
            // [期待結果] empty()
            false,
            // [期待結果] to_string()
            "people"
        },
        // _14
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 不適格(半角スペース)
            Table { "people", " " },
            // [期待結果] empty()
            false,
            // [期待結果] to_string()
            "people"
        },
        // _15
        {
            // [条件(1)]
            // + table :
            //     + alias_name : 適格
            Table { "people", "p" },
            // [期待結果] empty()
            false,
            // [期待結果] to_string()
            "people AS p"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__Table */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__identifier */)

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__TABLE_DATA_SET_HXX */
