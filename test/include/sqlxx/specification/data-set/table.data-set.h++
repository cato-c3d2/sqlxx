/*!
 * @file table.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__TABLE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__TABLE_DATA_SET_HXX

#include <vector>

#include <sql++/specification/table.class.h++>

#include "./table.data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__Table)

using sqlxx::specification::Table;

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::specification::Table              テスト対象クラス
 * @see sqlxx::specification::Table::empty()     テスト対象メンバ関数
 * @see sqlxx::specification::Table::to_string() テスト対象メンバ関数
 */
auto data_set() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + table_name : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _0
        {
            // + alias_name : 未指定
            Table {},
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _1
        {
            // + alias_name : 空文字列
            Table {}.alias_name(""),
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _2
        {
            // + alias_name : 不適格(半角スペース)
            Table {}.alias_name(" "),
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _3
        {
            // + alias_name : 適格
            Table {}.alias_name("p"),
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + table_name : 空文字列
        ////////////////////////////////////////////////////////////////////////
        // _4
        {
            // + alias_name : 未指定
            Table { "" },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _5
        {
            // + alias_name : 空文字列
            Table { "", "" },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _6
        {
            // + alias_name : 不適格(半角スペース)
            Table { "", " " },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _7
        {
            // + alias_name : 適格
            Table { "", "p" },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + table_name : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // _8
        {
            // + alias_name : 未指定
            Table { " " },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _9
        {
            // + alias_name : 空文字列
            Table { " ", "" },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _10
        {
            // + alias_name : 不適格(半角スペース)
            Table { " ", " " },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _11
        {
            // + alias_name : 適格
            Table { " ", "p" },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + table_name : 適格
        ////////////////////////////////////////////////////////////////////////
        // _12
        {
            // + alias_name : 未指定
            Table { "people" },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "people"
        },
        // _13
        {
            // + alias_name : 空文字列
            Table { "people", "" },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "people"
        },
        // _14
        {
            // + alias_name : 不適格(半角スペース)
            Table { "people", " " },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "people"
        },
        // _15
        {
            // + alias_name : 適格
            Table { "people", "p" },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "people AS p"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__Table */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__TABLE_DATA_SET_HXX */
