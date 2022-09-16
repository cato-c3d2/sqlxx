/*!
 * @file select-closure.data-set.16.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_16_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_16_HXX

#include <vector>

#include <sql++/closure/select-closure.class.h++>
#include <sql++/specification/column.class.h++>

#include "./select-closure.data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__SelectClosure)

using sqlxx::closure::SelectClosure;
using sqlxx::specification::Column;

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c columns[0] : @n
 * @li @c column_name : 適格
 * @li @c alias_name  : 適格
 *
 * @c columns[1] : @n
 * @li @c column_name : 未指定, 空文字列, 不適格(半角スペース) or 適格
 * @li @c alias_name  : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string_16() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // + columns[0] :
        //     + column_name : 適格
        //     + alias_name  : 適格
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 未指定
        ////////////////////////////////
        // _257
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 未指定
                Column {}
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },
        // _258
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 空文字列
                Column {}.alias_name("")
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },
        // _259
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 不適格(半角スペース)
                Column {}.alias_name(" ")
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },
        // _260
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 適格
                Column {}.alias_name("p.name")
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 空文字列
        ////////////////////////////////
        // _261
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 未指定
                Column { "" }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },
        // _262
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 空文字列
                Column { "", "" }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },
        // _263
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 不適格(半角スペース)
                Column { "", " " }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },
        // _264
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 適格
                Column { "", "p.name" }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, "
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 不適格(半角スペース)
        ////////////////////////////////
        // _265
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 未指定
                Column { " " }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id,  "
        },
        // _266
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 空文字列
                Column { " ", "" }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id,  "
        },
        // _267
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 不適格(半角スペース)
                Column { " ", " " }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id,   AS  "
        },
        // _268
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 適格
                Column { " ", "p.name" }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id,   AS p.name"
        },

        ////////////////////////////////
        // + columns[1] :
        //     + column_name : 適格
        ////////////////////////////////
        // _269
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 未指定
                Column { "name" }
            },
            // SQL 文字列 : 適格
            "SELECT id AS p.id, name"
        },
        // _270
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 空文字列
                Column { "name", "" }
            },
            // SQL 文字列 : 適格
            "SELECT id AS p.id, name"
        },
        // _271
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 不適格(半角スペース)
                Column { "name", " " }
            },
            // SQL 文字列 : 適格
            // "SELECT id AS p.id, name"
            // FIXME [要不具合修正] 実行結果と期待結果が一致しない
            "SELECT id AS p.id, name AS  "
        },
        // _272
        {
            SelectClosure {
                Column { "id", "p.id" },
                // + alias_name : 適格
                Column { "name", "p.name" }
            },
            // SQL 文字列 : 適格
            "SELECT id AS p.id, name AS p.name"
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_16_HXX */
