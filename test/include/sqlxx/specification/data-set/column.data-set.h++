/*!
 * @file column.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_HXX

#include <vector>

#include <sql++/specification/column.class.h++>

#include "./column-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__Column)

using sqlxx::specification::Column;

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::specification::Column              テスト対象クラス
 * @see sqlxx::specification::Column::empty()     テスト対象メンバ関数
 * @see sqlxx::specification::Column::to_string() テスト対象メンバ関数
 */
auto data_set() -> std::vector<ColumnDataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + column :
        //     + column_name : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _0
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 未指定
            Column {},
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _1
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 空文字列
            Column {}.alias_name(""),
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _2
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 不適格(半角スペース)
            Column {}.alias_name(" "),
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _3
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 適格
            Column {}.alias_name("p.id"),
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + column :
        //     + column_name : 空文字列
        ////////////////////////////////////////////////////////////////////////
        // _4
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 未指定
            Column { "" },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _5
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 空文字列
            Column { "", "" },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _6
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 不適格(半角スペース)
            Column { "", " " },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _7
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 適格
            Column { "", "p.id" },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + column :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////////////////////////////////////////////
        // _8
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 未指定
            Column { " " },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _9
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 空文字列
            Column { " ", "" },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _10
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 不適格(半角スペース)
            Column { " ", " " },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _11
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 適格
            Column { " ", "p.id" },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },

        ////////////////////////////////////////////////////////////////////////
        // [条件(0)]
        // + column :
        //     + column_name : 適格
        ////////////////////////////////////////////////////////////////////////
        // _12
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 未指定
            Column { "id" },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "id"
        },
        // _13
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 空文字列
            Column { "id", "" },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "id"
        },
        // _14
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 不適格(半角スペース)
            Column { "id", " " },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "id"
        },
        // _15
        {
            // [条件(1)]
            // + column :
            //     + alias_name : 適格
            Column { "id", "p.id" },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "id AS p.id"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__Column */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_HXX */
