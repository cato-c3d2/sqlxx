/*!
 * @file from-closure.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_HXX

#include <vector>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/identifier/table.class.h++>

#include "./from-closure-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__FromClosure)

using sqlxx::closure::FromClosure;
using sqlxx::identifier::Table;

auto data_set_a() -> std::vector<FromClosureDataSetElement>;
auto data_set_b() -> std::vector<FromClosureDataSetElement>;
auto data_set_c() -> std::vector<FromClosureDataSetElement>;
auto data_set_d() -> std::vector<FromClosureDataSetElement>;
auto data_set_e() -> std::vector<FromClosureDataSetElement>;

/*!
 * @brief  データセットを返却する
 *
 * [ データパターン表 ] @n
 * <pre>
 * -----------------------
 * |     |     table     |
 * =======================
 * |  _0 |       -       |
 * -----------------------
 *
 * -----------------------
 * |     |     table     |
 * |     | name  |  as   |
 * =======================
 * |  _1 |   -   |   -   |
 * |  _2 |   -   |   e   |
 * |  _3 |   -   |   x   |
 * |  _4 |   -   |   o   |
 * -----------------------
 * |  _5 |   e   |   -   |
 * |  _6 |   e   |   e   |
 * |  _7 |   e   |   x   |
 * |  _8 |   e   |   o   |
 * -----------------------
 * |  _9 |   x   |   -   |
 * | _10 |   x   |   e   |
 * | _11 |   x   |   x   |
 * | _12 |   x   |   o   |
 * -----------------------
 * | _13 |   o   |   -   |
 * | _14 |   o   |   e   |
 * | _15 |   o   |   x   |
 * | _16 |   o   |   o   |
 * -----------------------
 * </pre>
 *
 * [[ 凡例 ]] @n
 * @li o ... 指定(適格)
 * @li e ... 指定(不適格(空文字列))
 * @li x ... 指定(不適格(半角スペース))
 * @li - ... 未指定
 *
 * [[ 構成 ]] @n
 * @li        _0 : @link data_set_a() @endlink
 * @li  _1 ~  _4 : @link data_set_b() @endlink
 * @li  _5 ~  _8 : @link data_set_c() @endlink
 * @li  _9 ~ _12 : @link data_set_d() @endlink
 * @li _13 ~ _16 : @link data_set_e() @endlink
 *
 * @return データセット
 *
 * @see sqlxx::closure::FromClosure              テスト対象クラス
 * @see sqlxx::closure::FromClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::FromClosure::to_string() テスト対象メンバ関数
 */
auto data_set() -> std::vector<FromClosureDataSetElement>
{
    std::vector<std::vector<FromClosureDataSetElement>> data_set_parts = {
        // clang-format off
        data_set_a(),
        data_set_b(),
        data_set_c(),
        data_set_d(),
        data_set_e()
        // clang-format on
    };

    auto data_set = std::vector<FromClosureDataSetElement>();
    for (auto && data_set_part : data_set_parts) {
        data_set.insert(
            std::end(data_set),
            std::begin(data_set_part),
            std::end(data_set_part));
    }
    return data_set;
}

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c table : 未指定
 *
 * @return データセット
 *
 * @see sqlxx::closure::FromClosure              テスト対象クラス
 * @see sqlxx::closure::FromClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::FromClosure::to_string() テスト対象メンバ関数
 */
auto data_set_a() -> std::vector<FromClosureDataSetElement>
{
    // clang-format off
    return {
        // _0
        {
            // [条件]
            // + table : 未指定
            FromClosure {},
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        }
    };
}

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c table : @n
 * @li @c name       : 未指定
 * @li @c as_closure : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::FromClosure              テスト対象クラス
 * @see sqlxx::closure::FromClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::FromClosure::to_string() テスト対象メンバ関数
 */
auto data_set_b() -> std::vector<FromClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + table :
    //     + name : 未指定
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        // _1
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                Table {}
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _2
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                Table {}.as({ "" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _3
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                Table {}.as({ " " })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _4
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                Table {}.as({ "p" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        }
    };
}

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c table : @n
 * @li @c name       : 空文字列
 * @li @c as_closure : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::FromClosure              テスト対象クラス
 * @see sqlxx::closure::FromClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::FromClosure::to_string() テスト対象メンバ関数
 */
auto data_set_c() -> std::vector<FromClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + table :
    //     + name : 空文字列
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        // _5
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                Table { "" }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _6
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                Table { "" }.as({ "" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _7
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                Table { "" }.as({ " " })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _8
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                Table { "" }.as({ "p" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
    };
}

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c table : @n
 * @li @c name       : 不適格(半角スペース)
 * @li @c as_closure : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::FromClosure              テスト対象クラス
 * @see sqlxx::closure::FromClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::FromClosure::to_string() テスト対象メンバ関数
 */
auto data_set_d() -> std::vector<FromClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + table :
    //     + name : 不適格(半角スペース)
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        // _9
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                Table { " " }
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _10
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                Table { " " }.as({ "" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _11
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                Table { " " }.as({ " " })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _12
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                Table { " " }.as({ "p" })
            },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        }
    };
}

/*!
 * @brief データセットを返却する
 *
 * データパターン :
 *
 * @c table : @n
 * @li @c name       : 適格
 * @li @c as_closure : 未指定, 空文字列, 不適格(半角スペース) or 適格
 *
 * @return データセット
 *
 * @see sqlxx::closure::FromClosure              テスト対象クラス
 * @see sqlxx::closure::FromClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::FromClosure::to_string() テスト対象メンバ関数
 */
auto data_set_e() -> std::vector<FromClosureDataSetElement>
{
    ////////////////////////////////////////////////////////////////////////////
    // [条件(0)]
    // + table :
    //     + name : 適格
    ////////////////////////////////////////////////////////////////////////////
    // clang-format off
    return {
        // _13
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 未指定
                Table { "people" }
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "FROM people"
        },
        // _14
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 空文字列
                Table { "people" }.as({ "" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "FROM people"
        },
        // _15
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 不適格(半角スペース)
                Table { "people" }.as({ " " })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "FROM people"
        },
        // _16
        {
            FromClosure {
                // [条件(1)]
                // + table :
                //     + as_closure : 適格
                Table { "people" }.as({ "p" })
            },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "FROM people AS p"
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__FromClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_HXX */
