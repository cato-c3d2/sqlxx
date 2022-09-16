/*!
 * @file column.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_HXX

#include <vector>

#include <sql++/specification/column.class.h++>

#include "./column.data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__Column)

using sqlxx::specification::Column;

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::specification::Column              テスト対象クラス
 * @see sqlxx::specification::Column::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + column_name : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _0
        {
            // + alias_name : 未指定
            Column {},
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _1
        {
            // + alias_name : 空文字列
            Column {}.alias_name(""),
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _2
        {
            // + alias_name : 不適格(半角スペース)
            Column {}.alias_name(" "),
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _3
        {
            // + alias_name : 適格
            Column {}.alias_name("p.id"),
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + column_name : 空文字列
        ////////////////////////////////////////////////////////////////////////
        // _4
        {
            // + alias_name : 未指定
            Column { "" },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _5
        {
            // + alias_name : 空文字列
            Column { "", "" },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _6
        {
            // + alias_name : 不適格(半角スペース)
            Column { "", " " },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _7
        {
            // + alias_name : 適格
            Column { "", "p.id" },
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // + column_name : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // _8
        {
            // + alias_name : 未指定
            Column { " " },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            " "
        },
        // _9
        {
            // + alias_name : 空文字列
            Column { " ", "" },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            " "
        },
        // _10
        {
            // + alias_name : 不適格(半角スペース)
            Column { " ", " " },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "  AS  "
        },
        // _11
        {
            // + alias_name : 適格
            Column { " ", "p.id" },
            // SQL 文字列 : 不適格(空文字列)
            // ""
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "  AS p.id"
        },

        ////////////////////////////////////////////////////////////////////////
        // + column_name : 適格
        ////////////////////////////////////////////////////////////////////////
        // _12
        {
            // + alias_name : 未指定
            Column { "id" },
            // SQL 文字列 : 適格
            "id"
        },
        // _13
        {
            // + alias_name : 空文字列
            Column { "id", "" },
            // SQL 文字列 : 適格
            "id"
        },
        // _14
        {
            // + alias_name : 不適格(半角スペース)
            Column { "id", " " },
            // SQL 文字列 : 適格
            // "id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "id AS  "
        },
        // _15
        {
            // + alias_name : 適格
            Column { "id", "p.id" },
            // SQL 文字列 : 適格
            "id AS p.id"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__Column */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_HXX */
