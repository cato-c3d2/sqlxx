/*!
 * @file as-closure.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_HXX

#include <vector>

#include <sql++/closure/as-closure.class.h++>

#include "./as-closure-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__AsClosure)

using sqlxx::closure::AsClosure;

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::closure::AsClosure              テスト対象クラス
 * @see sqlxx::closure::AsClosure::empty()     テスト対象メンバ関数
 * @see sqlxx::closure::AsClosure::to_string() テスト対象メンバ関数
 */
auto data_set() -> std::vector<AsClosureDataSetElement>
{
    // clang-format off
    return {
        // _0
        {
            // [条件]
            // + alias_name : 未指定
            AsClosure {},
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _1
        {
            // [条件]
            // + alias_name : 空文字列
            AsClosure { "" },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _2
        {
            // [条件]
            // + alias_name : 不適格(半角スペース)
            AsClosure { " " },
            // [期待結果] empty メンバ関数
            true,
            // [期待結果] to_string メンバ関数
            ""
        },
        // _3
        {
            // [条件]
            // + alias_name : 適格(カラム指定)
            AsClosure { "p.id" },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "AS p.id"
        },
        // _4
        {
            // [条件]
            // + alias_name : 適格(テーブル指定)
            AsClosure { "p" },
            // [期待結果] empty メンバ関数
            false,
            // [期待結果] to_string メンバ関数
            "AS p"
        }
    };
}

BOOST_AUTO_TEST_SUITE_END(/* class__AsClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_HXX */