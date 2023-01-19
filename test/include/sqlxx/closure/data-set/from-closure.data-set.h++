/*!
 * @file from-closure.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_HXX

#include <vector>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/specification/table.class.h++>

#include "./from-closure.data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__FromClosure)

using sqlxx::closure::FromClosure;
using sqlxx::specification::Table;

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::closure::FromClosure              テスト対象クラス
 * @see sqlxx::closure::FromClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::FromClosure::to_string() テスト対象メンバ関数
 */
auto data_set() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + table : 未指定
        ////////////////////////////////////////////////////////////////////////
        // _0
        {
            FromClosure {},
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + table :
        //     + table_name : 未指定
        ////////////////////////////////
        // _1
        {
            FromClosure {
                // + alias_name : 未指定
                Table {}
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _2
        {
            FromClosure {
                // + alias_name : 空文字列
                Table {}.alias_name("")
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _3
        {
            FromClosure {
                // + alias_name : 不適格(半角スペース)
                Table {}.alias_name(" ")
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _4
        {
            FromClosure {
                // + alias_name : 適格
                Table {}.alias_name("p")
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + table :
        //     + table_name : 空文字列
        ////////////////////////////////
        // _5
        {
            FromClosure {
                // + alias_name : 未指定
                Table { "" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _6
        {
            FromClosure {
                // + alias_name : 空文字列
                Table { "", "" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _7
        {
            FromClosure {
                // + alias_name : 不適格(半角スペース)
                Table { "", " " }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _8
        {
            FromClosure {
                // + alias_name : 適格
                Table { "", "p" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + table :
        //     + table_name : 不適格(半角スペース)
        ////////////////////////////////
        // _9
        {
            FromClosure {
                // + alias_name : 未指定
                Table { " " }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _10
        {
            FromClosure {
                // + alias_name : 空文字列
                Table { " ", "" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _11
        {
            FromClosure {
                // + alias_name : 不適格(半角スペース)
                Table { " ", " " }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },
        // _12
        {
            FromClosure {
                // + alias_name : 適格
                Table { " ", "p" }
            },
            // 空判定 : 真
            true,
            // SQL 文字列 : 不適格(空文字列)
            ""
        },

        ////////////////////////////////
        // + table :
        //     + table_name : 適格
        ////////////////////////////////
        // _13
        {
            FromClosure {
                // + alias_name : 未指定
                Table { "people" }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "FROM people"
        },
        // _14
        {
            FromClosure {
                // + alias_name : 空文字列
                Table { "people", "" }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "FROM people"
        },
        // _15
        {
            FromClosure {
                // + alias_name : 不適格(半角スペース)
                Table { "people", " " }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "FROM people"
        },
        // _16
        {
            FromClosure {
                // + alias_name : 適格
                Table { "people", "p" }
            },
            // 空判定 : 偽
            false,
            // SQL 文字列 : 適格
            "FROM people AS p"
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__FromClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_HXX */
